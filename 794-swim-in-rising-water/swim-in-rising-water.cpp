class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0] = grid[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> qu;
        qu.push({dist[0][0],{0,0}});
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!qu.empty()){
            auto [val,it] = qu.top();
            qu.pop();
            auto [x,y] = it;
            if(val > dist[x][y]) continue;
            for(auto [dx,dy] : dir){
                int nx = x+dx, ny = y+dy;
                if(nx<n&& nx >=0 && ny<n && ny>=0){
                    if(dist[nx][ny] > max(val,grid[nx][ny])){
                        dist[nx][ny] = max(val,grid[nx][ny]);
                        qu.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return dist[n-1][n-1];

    }
};