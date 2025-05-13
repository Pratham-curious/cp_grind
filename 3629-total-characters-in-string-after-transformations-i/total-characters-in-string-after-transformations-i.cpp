class Solution {
public:
    #define ll long long
    const ll mod = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<ll> fir(26,0),sec(26,0);
        for(auto it : s){
            fir[it - 'a']++;
        }
        ll cnt = 1;
        while(cnt <= t){
            if(cnt & 1){
                for(int i=0;i<26;i++){
                    if(i == 25){
                        sec[0]= (sec[0]+fir[i])%mod;
                        sec[1]=(sec[1]+fir[i])%mod;
                    }
                    else{
                        sec[i+1]=(sec[i+1]+fir[i])%mod;
                    }
                    fir[i]=0;
                }
            }
            else{
                for(int i=0;i<26;i++){
                    if(i == 25){
                        fir[0] = (fir[0]+sec[i])%mod;
                        fir[1] = (fir[1]+sec[i])%mod;
                    }
                    else{
                        fir[i+1] = (fir[i+1]+sec[i])%mod;
                    }
                    sec[i]=0;
                }
            }
            cnt++;
        }
        ll ans = 0;
        for(auto it : fir) ans=(ans+it)%mod;
        for(auto it : sec) ans=(ans+it)%mod;
        return ans%mod;

    }
};