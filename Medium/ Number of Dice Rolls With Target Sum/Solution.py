# Problem: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
# You have n dice and each die has k faces numbered from 1 to k.
#
# Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the
# dice so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.
#
# Example 1:
# Input: n = 1, k = 6, target = 3
# Output: 1
# Explanation: You throw one die with 6 faces. There is only one way to get a sum of 3.
#
# Example 2:
# Input: n = 2, k = 6, target = 7
# Output: 6
# Explanation: You throw two dice, each with 6 faces. There are 6 ways to get a sum of 7:
# 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
#
# Example 3:
# Input: n = 2, k = 5, target = 10
# Output: 1
# Explanation: You throw two dice, each with 5 faces. There is only one way to get a sum of 10: 5+5.
#
# Example 4:
# Input: n = 1, k = 2, target = 3
# Output: 0
# Explanation: You throw one die with 2 faces. There is no way to get a sum of 3.
#
# Example 5:
# Input: n = 30, k = 30, target = 500
# Output: 222616187
# Explanation: The answer must be returned modulo 109 + 7.
#
# Constraints:
# 1 <= n <= 30
# 1 <= k <= 500
# 1 <= target <= 1000
class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        # 1. Create a list to store the number of ways to get the target
        dp = [[0] * (target + 1) for _ in range(n + 1)]
        # 2. Set the number of ways to get the target to 1
        dp[0][0] = 1
        # 3. Loop through the number of dice
        for i in range(1, n + 1):
            # 4. Loop through the target
            for j in range(1, target + 1):
                # 5. Loop through the number of faces
                for l in range(1, k + 1):
                    # 6. Check if the target is greater than the number of faces
                    if j >= l:
                        # 7. Add the number of ways to get the target
                        dp[i][j] += dp[i - 1][j - l]
        # 8. Return the number of ways to get the target
        return dp[-1][-1] % (10 ** 9 + 7)
