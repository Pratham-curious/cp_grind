class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(),m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int r = 0;
                if(i %2 == 0){
                     r = (j+k)%m;
                   
                }
                else{
                     r =  ((j-k)%m + m)%m;
                }
                if(mat[i][j] != mat[i][r]) return false;
                
            }
        }
        return true;

    }
};