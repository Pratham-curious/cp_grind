class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int cnt = 0;

        vector<vector<vector<int>>> v(n,vector<vector<int>>(m,vector<int>(201,0)));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i][j][matrix[i][j]]++;
                for(int k=0;k<=200;k++){
                    if(i- 1 >= 0 ) v[i][j][k] += v[i-1][j][k];
                    if(j - 1 >= 0)  v[i][j][k] += v[i][j-1][k];
                    if(i-1 >= 0 && j-1 >= 0)  v[i][j][k] -= v[i-1][j-1][k];
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val = 0;
                if(matrix[i][j] >  0){
                    int c2 = min(m-1,matrix[i][j] + j), c1 = j-matrix[i][j]-1;
                    int r2 = min(n-1,matrix[i][j] + i),r1 =  i-matrix[i][j]-1;
                    
                    for(int k=0;k<=200;k++){
                        int curr = v[r2][c2][k];
                        if(c1 >= 0) curr -= v[r2][c1][k];
                        if(r1 >= 0) curr -= v[r1][c2][k];
                        if(c1 >= 0 && r1 >= 0) curr += v[r1][c1][k];


                        if(r2 == matrix[i][j]+i && c2 == matrix[i][j]+j && matrix[r2][c2] == k) curr -= 1;

                        if(r1+1 >= 0 && c2 == matrix[i][j]+j && matrix[r1+1][c2] == k) curr -= 1;
                        if(c1+1 >= 0 && r2 == matrix[i][j]+i && matrix[r2][c1+1] == k) curr -= 1;
                        if(r1+1 >= 0 && c1+1 >= 0 && matrix[r1+1][c1+1] == k) curr -= 1;
                        
                        if(curr > 0) val = k;
                    }
                    if(val == matrix[i][j]) cnt++;
                }
               // cout<<val<<" ";
            }
           // cout<<endl;
        }

        return cnt;
    }
};