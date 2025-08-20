class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int mini = INT_MAX;
                if(matrix[i][j] == 1){
                    if(i-1 >= 0) mini = min(mini,matrix[i-1][j]);
                    if(j-1 >= 0) mini = min(mini,matrix[i][j-1]);
                    if(i-1 >= 0 && j-1>=0) mini = min(mini,matrix[i-1][j-1]);
                    if(i  == 0 || j == 0) mini = 0;
                    ans+=mini+1;
                    matrix[i][j] =1+mini;
                }
                else matrix[i][j] = 0;
            }
        }
        return ans;
    }
};