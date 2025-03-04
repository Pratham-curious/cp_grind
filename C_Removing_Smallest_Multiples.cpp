#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {
    ll n;
    cin >> n;
    string s;
    cin>>s;
    s = '0'+s;
    vector<ll> v(n+1,INT_MAX);
    for (ll i = 1; i <= n; i++) {
        if(s[i]=='0'){
            ll j = i;
            while(j<=n && s[j]=='0'){
                v[j]=min(v[j],i);
                j+=i;
            }
        }
    }
  // for(auto it : v) cout<<it<<" ";
    ll ans = 0;
    for(int i=n;i>=1;i--){
        if(v[i]!=INT_MAX){
            ans+=v[i];
          
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