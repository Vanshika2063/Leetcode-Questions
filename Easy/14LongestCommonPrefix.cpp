#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
      
        string ans;
        
  
        int minLen = 200;
        
     
        for(string s : strs)
            minLen = min(minLen, (int)s.length());
        
       
        for(int i=0; i<minLen; i++)
        {
           
            char ch = strs[0][i];
      
            for(int j=0; j<strs.size();j++)
            {
               
                if(strs[j][i] != ch)
                {
                    
                    return ans;
                }
            }
            
          
            ans.push_back(ch);
        }
        
        return ans;
    }
};


