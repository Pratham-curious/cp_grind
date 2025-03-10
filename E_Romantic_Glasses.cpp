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
    vector<ll> pref(n + 1, 0);
    map<ll, ll> mp;
    mp[0]++;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            pref[i] = pref[i - 1] + v[i-1];
        }
        else
        {
            pref[i] = pref[i - 1] - v[i-1];
        }
        mp[pref[i]]++;
    }
    for(auto it : mp){
        if(it.second>1){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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