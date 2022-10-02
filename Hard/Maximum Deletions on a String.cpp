/*
You are given a string s consisting of only lowercase English letters. In one operation, you can:

    Delete the entire string s, or
    Delete the first i letters of s if the first i letters of s are equal to the following i letters in s, for any i in the range 1 <= i <= s.length / 2.

For example, if s = "ababc", then in one operation, you could delete the first two letters of s to get "abc", since the first two letters of s and the following two letters of s are both equal to "ab".

Return the maximum number of operations needed to delete all of s.

Example 1:

Input: s = "abcabcdabc"
Output: 2
Explanation:
- Delete the first 3 letters ("abc") since the next 3 letters are equal. Now, s = "abcdabc".
- Delete all the letters.
We used 2 operations so return 2. It can be proven that 2 is the maximum number of operations needed.
Note that in the second operation we cannot delete "abc" again because the next occurrence of "abc" does not happen in the next 3 letters.

Example 2:

Input: s = "aaabaab"
Output: 4
Explanation:
- Delete the first letter ("a") since the next letter is equal. Now, s = "aabaab".
- Delete the first 3 letters ("aab") since the next 3 letters are equal. Now, s = "aab".
- Delete the first letter ("a") since the next letter is equal. Now, s = "ab".
- Delete all the letters.
We used 4 operations so return 4. It can be proven that 4 is the maximum number of operations needed.

Example 3:

Input: s = "aaaaa"
Output: 5
Explanation: In each operation, we can delete the first letter of s.


Solution :

*/

class Solution {
public:
    
    vector<int>fnc(string s){
        int n = s.size();
        vector<int> lps(n, 0);
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            j = lps[i - 1];
            while (j > 0 and s[i] != s[j])
            {
                j = lps[j - 1];
            }
            if (s[i] == s[j])
                j++;
            lps[i] = j;
        }
        return lps;
    }
    
    int deleteString(string s) {
        int cnt = 0;
        int itr = 0;
        while(true){
            bool ok = false;
            vector<int>lps = fnc(s);
            int val = 0;
            for(int i = 0;i < lps.size() / 2;i++){
                if(lps[i] == 0){
                    if(2 * (i + 1) - 1 < lps.size() and lps[2 * (i + 1) - 1] == i + 1){
                        val = max(val, i + 1);
                        ok = true;
                    }
                }
            }
            if(!ok){
                break;
            }
            else{
                s = s.substr(val);
                cnt++;
            }
        }
        cnt++;
        return cnt;
    }
};