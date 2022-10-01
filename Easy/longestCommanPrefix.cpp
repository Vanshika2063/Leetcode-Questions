class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0) return "";
        if(n==1) return strs[0]; 
        sort(strs.begin(),strs.end());

        string s=strs[0];
        string t=strs[n-1];
        int k= s.size();
        int l= t.size();
        int count =l;
        
        if(k>l) count=k;
        string ans="";
        for(int i=0;i<count;i++){
            if(s[i]==t[i]){
                ans+=s[i];
            }
            else break;
        }
        return ans;
    }
};