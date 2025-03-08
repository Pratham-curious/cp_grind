#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {
    ll n;
    cin >> n;

    vector<vector<ll>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<ll> col(n+1,-1);
    queue<ll> qu;
    qu.push(1);
    col[1]=1;
    while(!qu.empty()){
        ll top = qu.front();
        qu.pop();
        ll curr = col[top];
        for(auto it : adj[top]){
            if(col[it]==-1){
                col[it]=curr^1;
                qu.push(it);
            }
        }
    }
    ll ans = 0;
    ll total = 0;
    for(auto it : col) if(it == 0) total++;
    for(int i=1;i<=n;i++){
        if(col[i]==1){
            ll temp = total;
            for(auto it : adj[i]){
                if(col[it]==0) temp--;
            }  
            ans+=temp;
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
  //  cin >> tt;
    for (ll t = 1; t <= tt; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
