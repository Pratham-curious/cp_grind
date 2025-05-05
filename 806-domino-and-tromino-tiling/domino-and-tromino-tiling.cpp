class Solution {
public:
    #define ll long long
    const ll mod = 1e9+7;
    int numTilings(int n) {
        vector<ll> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(i>=1) dp[i] = (dp[i]+dp[i-1])%mod;
            if(i>=2) dp[i] = (dp[i]+dp[i-2])%mod;
            if(i>=3){
                for(int j=3;i-j>=0;j++) dp[i] = (dp[i] + 2*dp[i-j])%mod;
            }
        }
        return dp[n];
    }
};