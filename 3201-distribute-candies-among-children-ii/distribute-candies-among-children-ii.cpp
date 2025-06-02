class Solution {
public:
    #define ll long long
    ll cal(ll n){
        if( n < 0) return 0;
        return ((n+1)*(n+2))/2;
    }
    long long distributeCandies(int n, int limit) {
        return (cal(n) - 3ll*cal(n-(limit+1)) + 3ll*cal(n - 2*(limit+1)) - cal(n - 3*(limit+1)));
        
    }
};