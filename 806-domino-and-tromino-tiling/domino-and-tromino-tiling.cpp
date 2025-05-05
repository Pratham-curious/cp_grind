class Solution {
public:
    #define ll long long
    const long long mod = 1e9+7;
    ll cal(int n,vector<ll>& dp){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        ll sum = 0;
        if(n>=2) sum = (sum + cal(n-2,dp))%mod;
        if(n>=1) sum = (sum + cal(n-1,dp))%mod;
        if(n>=3) {
            for(int i=3;n-i>=0;i++) sum = (sum + 2*cal(n-i,dp))%mod;
        }
        return dp[n]=sum;

    }
    int numTilings(int n) {
        vector<ll> dp(n+1,-1);
        return cal(n,dp);
        
    }
};