class Solution {
public:
    void bfs(queue<pair<int,int>>& qu,vector<vector<bool>>& vis,vector<vector<int>>& height){
        int n = height.size(), m = height[0].size();
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        while(!qu.empty()){
            auto [x,y] = qu.front();
            qu.pop();
            for(auto [dx,dy] : dir){
                int nx = x+dx, ny = y+dy;
                if(nx<n && nx >=0 && ny < m && ny>=0 && !vis[nx][ny]){
                    if(height[nx][ny]>=height[x][y]){
                        vis[nx][ny] = true;
                        qu.push({nx,ny});
                    }
                }
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> Pacific(n,vector<bool>(m,false)), Atlantic(n,vector<bool>(m,false));
        queue<pair<int,int>> pac, atl;
        for(int i=0;i<n;i++){
            Pacific[i][0] = true;
            Atlantic[i][m-1] =true;
            pac.push({i,0});
            atl.push({i,m-1});
        }
        for(int i=0;i<m;i++){
            Pacific[0][i] = true;
            Atlantic[n-1][i] = true;
            pac.push({0,i});
            atl.push({n-1,i});
        }
        bfs(pac,Pacific,heights);
        bfs(atl,Atlantic,heights);
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(Pacific[i][j] && Atlantic[i][j]) ans.push_back(vector<int> {i,j});
            }
        }
        return ans;

    }
};