class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> dp(n+1,0);
        int mod = 1e9+7;
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            int res = 1;
            for(int j = 0;j<x;j++){
                res*=i;
                if(res > n) break;
            }
            if(res>n) break;
            for(int k=n;k>=res;k--){
                dp[k]=(dp[k]+dp[k-res])%mod;
            }
        }
        return dp[n]%mod;
    }
};