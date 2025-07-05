class Solution {
public:
#define ll long long 
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<ll>> dp(m,vector<ll>(n,LLONG_MAX));
        dp[m-1][n-1] = m*n;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if( i == m-1 && j == n-1) continue;
                ll mini = LLONG_MAX;
                if(i+1<m && j <n) mini = min(mini,dp[i+1][j]);
                if(i<m && j+1 <n) mini = min(mini,dp[i][j+1]);
                dp[i][j] = (i+1)*(j+1) + waitCost[i][j] + mini;
            }
        }
        return dp[0][0]-waitCost[0][0];
    }
};