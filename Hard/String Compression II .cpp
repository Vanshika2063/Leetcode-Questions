int dp[101][27][101][101];
class Solution {
public:
    string str;
    int n;
    int minLength(int i, int prev, int len, int k)
    {
        if(k<0)    return INT_MAX;
        if(i>=n)    return 0;
        if(dp[i][prev][len][k] != -1)   return dp[i][prev][len][k];
        int ifDelete = minLength(i+1,prev,len,k-1);
        int keep = 0;
        if(str[i]-'a' == prev)
        {
            if(len==1  len==99)     keep++;
            keep += minLength(i+1, prev, len+1, k);
        }
        else    keep = 1 + minLength(i+1, str[i]-'a', 1, k);
        return dp[i][prev][len][k] = min(ifDelete, keep);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        str = s;
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return minLength(0,26,0,k);
    }
}