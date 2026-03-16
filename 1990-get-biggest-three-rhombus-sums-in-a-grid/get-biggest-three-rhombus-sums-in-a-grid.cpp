class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        /// \\\

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> v1 = grid;
        vector<vector<int>> v2 = grid;

        for(int y=0;y<m;y++){
            int x = 0;
            for(int i=1;i<min(n,m);i++){
                if(x+i <n && y-i >=0){
                    int nx = x+i,ny = y-i;
                    v1[nx][ny]+=v1[nx-1][ny+1];
                }
            }
        }
        for(int x = 1;x < n ;x++){
            int y = m-1;
            for(int i=1;i<min(n,m);i++){
                if(x+i <n && y-i >=0){
                    int nx = x+i,ny = y-i;
                    v1[nx][ny]+=v1[nx-1][ny+1];
                }
            }
        }

        for(int y=0;y<m;y++){
            int x = 0;
            for(int i=1;i<min(n,m);i++){
                if(x+i <n && y+i<m){
                    int nx = x+i,ny = y+i;
                    v2[nx][ny]+=v2[nx-1][ny-1];
                }
            }
        }
        for(int x = 1;x<n;x++){
            int y=0;
            for(int i=1;i<min(n,m);i++){
                if(x+i <n && y+i<m){
                    int nx = x+i,ny = y+i;
                    v2[nx][ny]+=v2[nx-1][ny-1];
                }
            }
        }

        set<int> st;


        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
                st.insert(grid[x][y]);
                for(int inc = 1;inc < min(m,n);inc++){
                    if(x+2*inc < n && y-inc >=0 && y+inc < m){
                        int ans = 0;
                        ans += v1[x+inc][y-inc] - v1[x][y];
                        ans += v2[x+inc][y+inc] - v2[x][y];
                        ans += v1[x+2*inc][y] - v1[x+inc][y+inc];
                        ans += v2[x+2*inc][y] - v2[x+inc][y-inc];
                        ans += grid[x][y]-grid[x+2*inc][y];
                        st.insert(ans);
                    }
                }
            }
        }
        vector<int> ans;

        for(int i=0;i<3;i++){
            if(st.empty()) break;
            ans.push_back(*st.rbegin());
            st.erase(*st.rbegin());
        }
        return ans;
    }
};