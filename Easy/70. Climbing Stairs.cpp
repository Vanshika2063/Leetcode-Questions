class Solution {
public:
    int res(int n,vector<int> &dp){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]==-1){
            dp[n]=res(n-1,dp)+res(n-2,dp);
        }
        return dp[n];

    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return res(n,dp);
    }
};
