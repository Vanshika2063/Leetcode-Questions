/* Leetcode Problem: 62. Unique Paths
   Link: https://leetcode.com/problems/unique-paths/
*/

class Solution {
public:
    
    int helper(int row, int col, vector<vector<int>> &dp)
    {
        if(row < 0 || col < 0)
            return 0;
        if(row == 0 && col == 0)
            return 1;
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        int l = helper(row, col-1, dp);
        int u = helper(row-1, col, dp);
        
        return dp[row][col] = l + u;
    }
    
    
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        for(int i=0; i<m; i++)
            dp[i][0] = 1;
        for(int i=0; i<n; i++)
            dp[0][i] = 1;
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
               dp[i][j] =  dp[i][j-1] + dp[i-1][j];

        return dp[m-1][n-1];
    }
};
