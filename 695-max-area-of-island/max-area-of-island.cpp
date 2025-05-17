class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> qu;
        vector<vector<int>> temp = grid;
        vector<pair<int,int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt = 0;
                if(temp[i][j]==1){
                    qu.push({i,j});
                    temp[i][j]=0;
                    while(!qu.empty()){
                        auto top = qu.front();
                        qu.pop();
                        cnt++;
                        int x = top.first, y = top.second;
                        for(auto it : direction){
                            int dx = x+it.first, dy = y+it.second;
                            if(dx >= 0 && dx < n && dy >=0 && dy < m && temp[dx][dy]==1){
                                qu.push({dx,dy});
                                temp[dx][dy]=0;
                            }
                        }
                    }
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
        

    }
};