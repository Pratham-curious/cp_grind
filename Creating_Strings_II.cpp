#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const ll N = 1e6;
const ll P = 1e9+7;
vector<ll> fact(N+1);
vector<ll> infact(N+1);

ll inv(ll n){
    ll b = P-2;
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res*n)%P;
        n = (n*n)%P;
        b>>=1;
    }
    return res;
}

void precom(){
    
    fact[0]=1;
    for(int i = 1;i<=N;i++) fact[i] = (1ll*fact[i-1]*i) % P;
    infact[N] = inv(fact[N]);
    for(int i = N-1;i>=0;i--) infact[i] = (1ll*infact[i+1]*(i+1))%P;
}
void solve() {
    string s;
    cin>>s;
    ll n = s.size();
    map<ll,ll> mp;
    for(auto it : s) mp[it]++;
    ll ans = fact[n];
    for(auto it : mp){
        ll val = it.second;
        ans = (ans*infact[val])%P;
    }
    cout<<ans<<endl;



}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tt = 1;
    precom();

    // Uncomment the next line to read multiple test cases.
  //  cin >> tt;
    for (ll t = 1; t <= tt; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}