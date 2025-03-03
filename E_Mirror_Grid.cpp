#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve(ll t) {
    ll n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin>>s;
        v[i]=s;
    }
  // cout<<"WORKING"<<endl;
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ll val = v[i][j]-'0'+v[n-1-i][n-1-j]-'0'+v[j][n-1-i]-'0'+v[n-1-j][i]-'0';
            ans += min(val,4-val);
            v[i][j]='0';
            v[j][n-1-i]='0';
            v[n-1-i][n-1-j]='0';
            v[n-1-j][i]='0';
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
        solve(t);
    }
    return 0;
}