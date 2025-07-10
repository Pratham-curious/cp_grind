class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        queue<pair<int,int>> qu;
        vector<pair<int,int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    visited[i][j] = true;
                    qu.push({i,j});
                }
            }
        }
        int cnt = 0;
        while(!qu.empty()){
            int currSize = qu.size();
            cnt++;
            while(currSize--){
                auto [x,y] = qu.front();
                qu.pop();
                for(auto [dx,dy] : direction){
                    int nx = x+dx, ny = y+dy;
                    if(nx < n && nx >=0 && ny >=0 && ny < m){
                        if(grid[nx][ny] == 1 && !visited[nx][ny]){
                            visited[nx][ny] = true;
                            qu.push({nx,ny});

                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 && !visited[i][j]) return -1;
            }
        }
        return max(0,cnt-1);
    }
};