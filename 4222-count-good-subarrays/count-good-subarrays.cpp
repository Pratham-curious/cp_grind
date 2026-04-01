class Solution {
public:
#define ll long long

/*

1e3 < 2^10

*/
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>> pref(n,vector<ll>(31,-1)),suff(n,vector<ll>(31,n));

    
        for(int i=0;i<n;i++){
            if(i > 0) pref[i] = pref[i-1];
            int temp = nums[i];
            for(int j=0;j<=30;j++){
                if(temp & (1ll << j)){
                    pref[i][j] = i;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i < n-1) suff[i] = suff[i+1];
            int temp = nums[i];
            for(int j=0;j<=30;j++){
                if(temp & (1ll << j)){
                    suff[i][j] = i;
                }
            }
        }

        ll ans = 0;
        unordered_map<ll,ll> mp;
        for(int i=0;i<n;i++){

            int temp = nums[i];
            ll l = -1,r = n;

            if(mp.find(nums[i])!= mp.end()) l = mp[nums[i]];

            for(int j=0;j<=30;j++){
                if((temp & (1ll << j)) == 0){
                    l = max(l,pref[i][j]);
                    r = min(r,suff[i][j]);
                }
            }
            ans += (r-i)*(i-l);
            mp[nums[i]] = i;
        }
        return ans;
        
    }
};