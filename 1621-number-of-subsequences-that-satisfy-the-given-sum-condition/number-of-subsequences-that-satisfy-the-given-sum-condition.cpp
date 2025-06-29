class Solution {
public:
    #define ll long long
    const ll mod = 1e9+7;

    ll expo(ll a, ll b){
        ll res = 1;
        while(b>0){
            if(b&1) res =(res*a)%mod;
            a = (a*a)%mod;
            b>>=1;
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        ll ans = 0;
        ll n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int val = target-nums[i];
            auto it = upper_bound(nums.begin(),nums.end(),val)-nums.begin();
            if(it == 0) continue;
            --it;
            ll len = (it-i >= 0) ? expo(2,it-i) : 0;
            ans = (ans+len)%mod;
        }
        return ans;
    }
};