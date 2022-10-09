class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int> > q;
        int time = 0;
        int count = 0;
        int orange = 0;
        
        int m  = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1 || grid[i][j] == 2)
                    orange++;
            
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        
        if(orange == 0)
            return 0;
        
        if(q.size() == 0)
            return -1;
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!q.empty()) {
            int k = q.size();
            count += k;
            while(k--) {
                vector<int> curr = q.front();
                q.pop();
                int x = curr[0];
                int y = curr[1];
                
                for(int i=0; i<4; i++) {
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    
                    if(nx<0 || nx>=m || ny<0 || ny>=n || grid[nx][ny] != 1)
                        continue;
                    
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty())
                time++;
        }
        
        return count==orange ? time : -1;
    }
};