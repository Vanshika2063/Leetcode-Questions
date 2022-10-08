class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& OG) {
        if (OG[0][0] == 1) return 0;
        int m = OG.size(), n = OG[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (OG[i][j] == 1 || (i == 0 && j == 0)) continue;
                else dp[i][j] = (i > 0 ? dp[i-1][j] : 0) + (j > 0 ? dp[i][j-1] : 0);
        return dp[m-1][n-1];
    }
};
