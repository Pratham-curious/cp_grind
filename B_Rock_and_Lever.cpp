#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll cal(ll n){
    ll cnt = 0;
    while(n>0){
        cnt++;
        n>>=1;
    }
    return cnt;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    map<ll,ll> mp;
    for(auto it : v){
        mp[cal(it)]++;
    }
    ll ans = 0;
    for(auto it : mp){
        ans += ((it.second)*(it.second -1))/2;
    }
    cout<<ans<<endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tt = 1;
    // Uncomment the next line to read multiple test cases.
    cin >> tt;
    for (ll t = 1; t <= tt; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}