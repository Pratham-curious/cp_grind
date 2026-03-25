class Solution {
public:
#define ll long long
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<ll> row(n,0),col(m,0);

        for(int i=0;i<n;i++){
            if(i > 0) row[i]+=row[i-1];
            for(int j=0;j<m;j++){
                row[i]+=grid[i][j];
            }
        }
        if(row[n-1]%2 == 0){
            for(int i=0;i<n;i++){
                if(row[i] == row[n-1]/2) return true;
            }
        }
        for(int i=0;i<m;i++){
            if(i > 0) col[i]+=col[i-1];
            for(int j=0;j<n;j++){
                col[i]+=grid[j][i];
            }
        }
        if(col[m-1]%2 == 0){
            for(int i=0;i<m;i++){
                if(col[i] == col[m-1]/2) return true;
            }
        }
        return false;
    }
};