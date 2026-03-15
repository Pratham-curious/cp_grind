class Solution {
public:
#define ll long long
    long long countCommas(long long n) {
         ll ans = 0;
        // 1000 ->1, 100,000 -> 2
        ll curr = 1;
        for(int i=0;i<6;i++){
            curr*=1000;
            if(curr > n) break;
            ans += max(0ll,n-(curr-1));
        }
        return ans;
    }
};