class Solution {
public:
    #define ll long long
    const int mod = 1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<ll>>> v(n,vector<vector<ll>> (m,vector<ll>(2)));
        v[n-1][m-1] = {LLONG_MIN,grid[n-1][m-1]};
        if(grid[n-1][m-1] > 0) v[n-1][m-1] = {grid[n-1][m-1],LLONG_MAX};



// 0 - > positive, 1 -> negative 

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i == n-1 && j == m-1) continue;
                v[i][j] = {LLONG_MIN,LLONG_MAX};
                if(i+1 < n){
                    if(grid[i][j] < 0){
                        if(v[i+1][j][0] != LLONG_MIN) v[i][j][1] = min((v[i+1][j][0]*grid[i][j]),v[i][j][1]);
                        if(v[i+1][j][1] != LLONG_MAX) v[i][j][0] = max(v[i][j][0], (grid[i][j]*v[i+1][j][1]));
                    }
                    else{
                        if(v[i+1][j][1] != LLONG_MAX) v[i][j][1] = min((v[i+1][j][1]*grid[i][j]),v[i][j][1]);
                        if(v[i+1][j][0] != LLONG_MIN) v[i][j][0] = max(v[i][j][0], (grid[i][j]*v[i+1][j][0]));
                    }
                }
                if(j+1 < m){
                    if(grid[i][j] < 0){
                        if(v[i][j+1][0] != LLONG_MIN) v[i][j][1] = min((v[i][j+1][0]*grid[i][j]),v[i][j][1]);
                        if(v[i][j+1][1] != LLONG_MAX) v[i][j][0] = max(v[i][j][0], (grid[i][j]*v[i][j+1][1]));
                    }
                    else{
                        if(v[i][j+1][1] != LLONG_MAX) v[i][j][1] = min((v[i][j+1][1]*grid[i][j]),v[i][j][1]);
                        if(v[i][j+1][0] != LLONG_MIN) v[i][j][0] = max(v[i][j][0], (grid[i][j]*v[i][j+1][0]));
                    }
                }
            }
        }
        if(v[0][0][0] == LLONG_MIN) {
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++) if(grid[i][j] == 0) return 0;
            }
            return -1;
        }
        return v[0][0][0]%mod;
    }
};