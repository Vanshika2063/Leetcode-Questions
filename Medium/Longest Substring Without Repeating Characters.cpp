// Given a string s, find the length of the longest substring without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
 map<char,int> m;
    int temp=0, ans=INT_MIN,reset_i=0;
    for(int i=0;i<s.length();i++)
    {
        m[s[i]]++;
        temp++;
        if(m[s[i]]>1)
        {
            map<char,int> :: iterator it;
            for(it=m.begin();it!=m.end();it++)
                it->second=0;
            temp--;
            i=reset_i++;
            ans = max(ans,temp);
            temp=0;}
    }
   return max(ans,temp);
}
};