class Solution {
public:
#define ll long long
    ll cal(ll n){
        ll low = 1, high = 1e8;
        while(low <= high){
            ll m = low + (high-low)/2;
            ll val = (m*(m+1)/2);
            if(val <= n) low = m+1;
            else high = m-1;
        }
        return high;
    }
    bool check(vector<int>& v,ll m,int height){
        ll x = 0;
        for(auto it : v){
            ll day = cal(m/it);
            if(x + day >= height) return true;
            x += day;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll low = 1,high = 1e17;
        while(low <= high){
            ll m = low + (high-low)/2;
            if(check(workerTimes,m,mountainHeight)) high = m-1;
            else low = m+1;
        }
        return low;
    }
};