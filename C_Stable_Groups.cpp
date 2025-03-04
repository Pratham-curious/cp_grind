#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {
    ll n,k,x;
    cin >> n>>k>>x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    priority_queue<ll,vector<ll>,greater<ll>> qu;
    for(int i=1;i<n;i++){
        if(v[i]-v[i-1]>x) qu.push(v[i]-v[i-1]); 
    }
    while(k>0 && !qu.empty()){
        ll top = qu.top();
       
        k-=(top-1)/x;
        if(k< 0) break;
        qu.pop();
    }
    cout<<qu.size()+1<<endl;


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