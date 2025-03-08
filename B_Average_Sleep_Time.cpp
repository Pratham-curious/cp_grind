#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {
    ll n,k;
    cin >> n>>k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll sum = 0;
    for(int i=0;i<k;i++) sum+=v[i];
    ll ans = sum;
    for(int i=k;i<n;i++){
        sum = sum+v[i]-v[i-k];
        ans+=sum;
    }
    long double val = (long double)ans/(n-k+1);
    cout << std::fixed << std::setprecision(6) << val << std::endl;



}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tt = 1;
    // Uncomment the next line to read multiple test cases.
   // cin >> tt;
    for (ll t = 1; t <= tt; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}