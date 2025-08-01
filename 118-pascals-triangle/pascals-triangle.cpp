class Solution {
public:
    int cal(int row,int col,vector<vector<int>>& dp){
        if(col < 0 || col > row) return 0;
        if(col == 0 && row == 0) return dp[row][col] = 1;
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = cal(row-1,col-1,dp) + cal(row-1,col,dp);
        
        
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows,vector<int>(numRows,-1));
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            cal(numRows-1,i,dp);
        }
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            for(int j = 0;j<=i;j++){
                temp.push_back(dp[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};