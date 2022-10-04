class Solution {
public:
    bool isPossible(string &s,int i,int j , unordered_map<string,int> &hm,int len){
        
        unordered_map<string,int> freq;   // map frequency of each word occuring in this window 
        int k = i;
        while(k<j-len+2){
           string str = s.substr(k,len);
            freq[str]++;
            k+=len;
        }
        
        for(auto i : freq){
            if(i.second != hm[i.first])return false;   // if frequency of any word differs from the frequency we want ( stored in hm) return false
        }
        
  
        return true;
        
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        
    
        
       unordered_map<string,int> hm;
        for(int k = 0;k<words.size();k++){  // store frequency of words 
            hm[words[k]]++;
        }
        
      int windowSize = words.size()*(words[0].size());  // take window size such that it cover each word
       int i =0,j = windowSize-1;
        
        vector<int> ans;    // ans vector  
        
        while(j<s.size()){    // apply sliding window 
            
         if(isPossible(s,i,j,hm,words[0].size()))ans.push_back(i);  // if the window contains all words (see function above)  push the index in ans  
            i++;
            j++;  
        }
        
        return ans;
        
    }
};