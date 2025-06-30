class Solution {
public:
    #define ll long long
    const ll mod = 1e9+7;
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<ll>> dp(6,vector<ll>(16,0));
        for(int i=0;i<6;i++){
            dp[i][1]=1;
        }

        for(int i=1;i<n;i++){
            vector<vector<ll>> ndp(6,vector<ll>(16,0));
            
            for(int last=0;last<6;last++){
                for(int run =1;run<=rollMax[last];run++){
                    ll ways = dp[last][run];

                    if(run < rollMax[last]){
                        ndp[last][run+1] = (ndp[last][run+1]+ways)%mod;
                    }

                    for(int next =0;next<6;next++){
                        if(last == next) continue;
                        ndp[next][1] = (ndp[next][1]+ways)%mod;
                    }
                }
            }
            dp.swap(ndp);
        }

        ll ans = 0;
        for(int c = 0;c<6;c++){
            for(int run=1;run<=rollMax[c];run++){
                ans = (ans+dp[c][run])%mod;
            }
        }
        return ans;

    }
};