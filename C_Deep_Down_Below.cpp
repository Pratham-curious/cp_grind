#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

bool check(vector<pair<ll,ll>>& v,ll tar){
    int n = v.size();
    ll curr = tar;
    for(int i=0;i<n;i++){
        if(curr<v[i].first) return false;
        curr += v[i].second;
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> v(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin>>x;
        for(int j=0;j<x;j++){
            ll y;
            cin>>y;
            v[i].pb(y);
        }
    }
    
    vector<pair<ll,ll>> temp;
    for(int i=0;i<n;i++){
        ll m = v[i].size();
        ll maxi = 0;
        for(int j=0;j<m;j++){
            maxi = max(maxi,v[i][j]-j+1);
        }
        temp.pb({maxi,m});
    }
    sort(temp.begin(),temp.end());
    ll low = 1, high = 1e12;
    while(low<=high){
        ll mid = low + (high-low)/2;
        
        if(check(temp,mid)) high = mid-1;
        else low = mid+1;
    }
    cout<<low<<endl;

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