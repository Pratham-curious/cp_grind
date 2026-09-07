class Solution {
public:
    const int mod = 1e9+7;
    int distinctSubseqII(string s) {
        int n = s.size();
        int ans = 0;

        vector<int> dp(n,0);

        for(int i=0;i<n;i++){
            bool dup = false;
            for(int j=i-1;j>=0;j--){
                if(s[i] == s[j]){
                    dup = true;
                    dp[i] = (dp[i]+dp[j])%mod;
                    break;
                } 
                else dp[i] = (dp[i] + dp[j])%mod;
            }
            if(!dup) dp[i] = (dp[i]+1)%mod;
        }
        for(auto it : dp) ans = (ans+it)%mod;
        return ans;
    }
};