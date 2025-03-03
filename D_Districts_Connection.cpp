#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    map<ll, vector<ll>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]].pb(i + 1);
    }
    if(mp.size()==1){
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        auto next_it = std::next(it);
        if (next_it != mp.end())
        {
            for(auto val : next_it->second){
                cout<<(it->second)[0]<<" "<<val<<'\n';
            }
        }
    }
    auto it = mp.begin();
    auto next_it = std::next(it);
    for(int i=1;i<(it->second).size();i++){
        cout<<(next_it->second)[0]<<" "<<(it->second)[i]<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tt = 1;
    // Uncomment the next line to read multiple test cases.
    cin >> tt;
    for (ll t = 1; t <= tt; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}