#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<pair<ll,ll>> temp;
    for(int i=0;i<n;i++){
        temp.pb({b[i]-a[i],i+1});
    }
    sort(temp.begin(),temp.end());
    vector<ll> df;
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(temp[i].first==temp[0].first) df.pb(temp[i].second);
    }
    cout<<df.size()<<endl;
    for(auto it:df) cout<<it<<" ";
    cout<<endl;


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