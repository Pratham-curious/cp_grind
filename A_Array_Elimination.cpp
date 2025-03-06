#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll gcd(ll a, ll b){
    while(b>0){
        a%=b;
        swap(a,b);
    }
    return a;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<ll> dig(61,0);
    for(auto it : v){
        for(int i=60;i>=0;i--){
            ll val =(it & (1ll<<i)) > 0 ;
            dig[i]+=val;
        }
    }
    ll temp = 0;
    for(auto it : dig) temp = gcd(it,temp);
    vector<ll> ans;
    if(temp == 0){
        for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<endl;
        return;
    }
    for(ll i=1;i*i<=temp;i++){
        if(temp%i == 0){
            ans.pb(i);
            if(temp/i != i) ans.pb(temp/i);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto it : ans) cout<<it<<" ";
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