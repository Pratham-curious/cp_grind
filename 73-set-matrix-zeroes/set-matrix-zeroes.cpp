class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool fir = false;
        for(int j=0;j<m;j++) if(matrix[0][j]==0) fir = true;
    
        for(int i=1;i<n;i++){
            bool found = false;
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    found = true;
                    matrix[0][j]=0;
                }
            }
            if(found){
                for(int k=0;k<m;k++) matrix[i][k]=0;
            }
        }

        for(int j=0;j<m;j++){
            if(matrix[0][j]==0){
                for(int i=0;i<n;i++) matrix[i][j]=0;
            }
        }

        if(fir) for(int j=0;j<m;j++) matrix[0][j]=0;

    }
};