// Problem - https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution {
public:
  int balancedStringSplit(string s) {
    int i, n = s.length(), R = 0, cnt = 0;
    
    for(i = 0; i < n; i++){
      if(s[i] == 'R'){
        R++;
        if(R == 0) cnt++;
      }

      else
      {
        R--;
        if(R == 0) cnt++;
      }
    }
    
    return cnt;
  }
};