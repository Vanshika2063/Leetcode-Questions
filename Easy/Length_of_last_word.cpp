class Solution {
public:
    int lengthOfLastWord(string s) {
        int t=s.length();
        int c=0;
        for(int i=t-1;i>=0;i--)
        {
            if(s[i]==' '&&c!=0)
                return c;
             else if((c==0)&&(s[i]==' '))
                 continue;
            else
                 c++;
        }
            return c;
         }
};