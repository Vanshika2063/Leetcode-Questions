class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int sum = 0, ans = INT_MIN;
        for(int i = 0; i < row-2; i++){
            for(int j = 0; j < col-2; j++){
                int sum = (grid[i][j]+grid[i][j+1]+grid[i][j+2])+
                      (grid[i+1][j+1])+
                  (grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]);
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};