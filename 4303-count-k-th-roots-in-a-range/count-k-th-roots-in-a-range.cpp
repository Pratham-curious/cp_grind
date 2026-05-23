class Solution {
public:
/*

1. l <= x^k (y) <= r

    ->  

2. 1 <= k <= 30


*/
#define ll long long


ll pow(ll n,int k){
    ll ans = 1;
    while(k > 0){
        if(k & 1) ans *=n ;
        n *= n ;
        k >>= 1;
    }
    return ans;
}

    int countKthRoots(int l, int r, int k) {
        if(k == 1){
            return r-l+1;
        }
        vector<int> v;
        for(ll i=0;i<=r;i++){
            ll val = pow(i,k);
            if(val > r) break;
            v.push_back(val);
        }

        int low = lower_bound(v.begin(),v.end(),l) - v.begin();
        int high = upper_bound(v.begin(),v.end(),r) - v.begin();
        return high-low;
    }
};