class Solution
{
private:
    int mx = 0, m, n, cur = 0;

    void dfs(vector<vector<int>> &grid, int x, int y)
    {
        if (x < 0 || x >= m || y < 0 || y >= n || !grid[x][y])
            return;
        grid[x][y] = 0;
        ++cur;
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    cur = 0;
                    dfs(grid, i, j);
                    mx = max(cur, mx);
                }
            }
        }

        return mx;
    }
};
