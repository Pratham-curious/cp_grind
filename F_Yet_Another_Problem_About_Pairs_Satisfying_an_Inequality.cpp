#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll search(vector<ll>& v, ll tar){
    if(v.empty()) return 0;
    ll low = 0, high = v.size()-1;
    ll ans = 0;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(v[mid]<tar){
            ans = mid+1;
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n+1,0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<ll> cal;
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        if(i-v[i]>0){
            ans+=search(cal,v[i]);
            cal.pb(i);
        }
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