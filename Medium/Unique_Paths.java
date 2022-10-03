class Solution {
public int uniquePaths(int m, int n) {
//call recursive method
//return uniquePathsRec(m, n, m-1, n-1);

    int[][] dp = new int[m+1][n+1];
    for(int i=0; i<m+1; i++){
        Arrays.fill(dp[i], -1);
    }
    //call memoized method
    //return uniquePathsMem(m, n, m-1, n-1, dp);
    
    //call tabular method
    return uniquePathsTab(m, n, m-1, n-1, dp);
    
}
public int uniquePathsRec(int m, int n, int i, int j){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    
    return uniquePathsRec(m, n, i-1, j) + uniquePathsRec(m, n, i, j-1);
}

public int uniquePathsMem(int m, int n, int i, int j, int[][] dp){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    
    if(dp[m][n] != -1) return dp[m][n];
    return dp[i][j] = uniquePathsMem(m, n, i-1, j, dp) + uniquePathsMem(m, n, i, j-1, dp);
}

public int uniquePathsTab(int m, int n, int i, int j, int[][] dp){
    dp[0][0] = 1;
    
    for(int r=0; r<m; r++){
        for(int c=0; c<n; c++){
            if(r==0 && c==0){
                dp[r][c] = 1;
            }
            else{
                int up = 0;
                int down = 0;
                if(r>0){
                    up += dp[r-1][c];
                }
                if(c>0){
                    down += dp[r][c-1];
                }
                dp[r][c] = up + down;
            }
        }
    }
    return dp[m-1][n-1];
}
}
