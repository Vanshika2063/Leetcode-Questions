# Problem: https://leetcode.com/problems/decode-ways/
#
# A message containing letters from A-Z is being encoded to numbers using the following mapping: 'A' -> 1 'B' -> 2
# ... 'Z' -> 26 To decode an encoded message, all the digits must be grouped then mapped back into letters using the
# reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into: "AAJF" with the
# grouping (1 1 10 6) "KJF" with the grouping (11 10 6) Note that the grouping (1 11 06) is invalid because "06"
# cannot be mapped into 'F' since "6" is different from "06". Given a string s containing only digits, return the
# number of ways to decode it. The answer is guaranteed to fit in a 32-bit integer. Given s = "12", return 2. It
# could be decoded as "AB" (1 2) or "L" (12). The answer is guaranteed to fit in a 32-bit integer. Example 1: Input:
# s = "12" Output: 2 Explanation: It could be decoded as "AB" (1 2) or "L" (12). Example 2: Input: s = "226" Output:
# 3 Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6). Example 3: Input: s = "0" Output:
# 0 Explanation: There is no character that is mapped to a number starting with 0. The only valid mappings with 0 are
# 'J' -> "10" and 'T' -> "20", neither of which start with 0. Hence, there are no valid ways to decode this since all
# digits need to be mapped. Example 4: Input: s = "1" Output: 1 Constraints: 1 <= s.length <= 100 s contains only
# digits and may contain leading zero(s).
class Solution:
    def numDecodings(self, s: str) -> int:
        # 1. Check if the string is empty
        # 2. Check if the string is 0
        if not s or s[0] == '0':
            return 0
        # 3. Create a list to store the number of ways to decode
        dp = [0] * (len(s) + 1)
        dp[0] = 1
        dp[1] = 1
        # 4. Loop through the string
        for i in range(2, len(s) + 1):
            # 5. Check if the current character is 0
            if 0 < int(s[i - 1:i]) <= 9:
                dp[i] += dp[i - 1]
            # 6. Check if the current character and the previous character is between 10 and 26
            if 10 <= int(s[i - 2:i]) <= 26:
                # 7. Add the number of ways to decode the previous character
                dp[i] += dp[i - 2]
        # 8. Return the number of ways to decode the string
        return dp[-1]
