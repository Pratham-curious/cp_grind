class Solution {
public:
    const int mod = 1e9+7;

    int numberOfSets(int n, int k) {
       const int MOD = 1e9 + 7;
    vector<int> dp(k + 1, 0), sum_dp(k + 1, 0);
    
    dp[0] = sum_dp[0] = 1;

    for (int i = 1; i < n; i++) {
        vector<int> next_dp(k + 1, 0);
        next_dp[0] = 1;
        for (int m = 1; m <= k; m++) {
            next_dp[m] = (dp[m] + sum_dp[m - 1]) % MOD;
        }
        dp = move(next_dp);
        for (int m = 0; m <= k; m++) {
            sum_dp[m] = (sum_dp[m] + dp[m]) % MOD;
        }
    }
    return dp[k];
    }
};