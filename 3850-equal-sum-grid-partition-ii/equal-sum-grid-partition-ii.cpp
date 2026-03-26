class Solution {
public:
#define ll long long
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<ll> pref(n,0), col(m,0);
        
      
        unordered_map<ll, int> m1, m2;

        for(int i=0; i<n; i++){
            if(i > 0) pref[i] += pref[i-1];
            for(int j=0; j<m; j++){ 
                pref[i] += grid[i][j];
                m1[grid[i][j]]++;
            }
        }
        
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++) {
                m1[grid[i][j]]--;
                m2[grid[i][j]]++;
            }
            ll x = pref[i], y = pref[n-1] - pref[i];
            
            if(x == y) return true;
            else if(x > y){
                if(i > 0 && m > 1 && m2.count(x-y) && m2[x-y] > 0) return true;
                if(x-y == grid[0][0] || x-y == grid[0][m-1]) return true;
            }
            else {
                if(n-1-i > 1 && m > 1 && m1.count(y-x) && m1[y-x] > 0){
                    return true;
                }
                if(y-x == grid[n-1][0] || y-x == grid[n-1][m-1]) return true;
            } 
            if(m == 1){
                if(x-y == grid[i][0] || x-y == grid[0][0]) return true;
                if(y-x == grid[i+1][0] || y-x == grid[n-1][0]) return true;
            }   
        }
        for(int j=0;j<m;j++) m2[grid[n-1][j]]++;
        

        for(int i=0; i<m; i++){
            if(i > 0) col[i] += col[i-1];
            for(int j=0; j<n; j++){ 
                col[i] += grid[j][i];
            }
        }
        
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n; j++) {
                m2[grid[j][i]]--;
                m1[grid[j][i]]++;
            }
            ll x = col[i], y = col[m-1] - col[i];
            
            if(x == y) return true;
            else if(x > y){
                if(i > 0 && n > 1 && m1.count(x-y) && m1[x-y] > 0) return true;
                if(x-y == grid[0][0] || x-y == grid[n-1][0]) return true;
            }
            else{
                if(m-1-i > 1 && n > 1 && m2.count(y-x) && m2[y-x] > 0) return true;
                if(y-x == grid[0][m-1] || y-x == grid[n-1][m-1]) return true;
            }
            if(n == 1){
                if(x-y == grid[0][i] || x-y == grid[0][0]) return true;
                if(y-x == grid[0][i+1] || y-x == grid[0][m-1]) return true;
            }
        }

        return false;
    }
};