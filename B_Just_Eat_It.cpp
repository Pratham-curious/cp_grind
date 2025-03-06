#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll sum = 0;
    for(auto it : v) sum+=it;
    ll maxi = LLONG_MIN;
    ll curr = 0;
    for(int i=0;i<n-1;i++){
        curr+=v[i];
        maxi = max(curr,maxi);
        if(curr<=0) curr=0;
    }
    curr=0;
    for(int i=1;i<n;i++){
        curr+=v[i];
        maxi = max(curr,maxi);
        if(curr<=0) curr=0;
    }
    if(sum > maxi ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


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