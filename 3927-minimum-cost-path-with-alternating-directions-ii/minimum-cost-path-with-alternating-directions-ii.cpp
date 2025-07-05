class Solution {
public:
#define ll long long 
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<ll> dp(n,0);
        for(int i=m-1;i>=0;i--){
            vector<ll> temp(n,LLONG_MAX);
            for(int j=n-1;j>=0;j--){
                if( i == m-1 && j == n-1) {temp[j]=m*n; continue;}
                ll mini = LLONG_MAX;
                if(i+1<m && j<n) mini = min(mini,dp[j]);
                if(i<m && j+1 <n) mini = min(mini,temp[j+1]);
                temp[j] = (i+1)*(j+1) + waitCost[i][j] + mini;
            }
            dp = temp;
        }
        return dp[0]-waitCost[0][0];
    }
};