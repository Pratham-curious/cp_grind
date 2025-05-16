class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        dp[n-1] = triangle[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];

    }
};