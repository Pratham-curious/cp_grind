class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        vector<vector<int>> dp(n + 1);
        dp[0] = {1};
        for (int i = 1; i <= n; i++) {
            dp[i].push_back(1);
            for(int j = 0;j<dp[i-1].size()-1;j++){
                dp[i].push_back(dp[i-1][j]+dp[i-1][j+1]);
            }
            dp[i].push_back(1);
        }
        return dp[n];
    }
};