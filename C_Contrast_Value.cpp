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
    bool err = false;
    for(auto it : v) if(v[0]!=it) err = true;
    if(!err){
        cout<<1<<endl;
        return;
    }
    ll cnt = 1;
    ll i = 1;
    while (i < n )
    {
        while(i<n && v[i] == v[i - 1]) i++;

        if (i< n && v[i] <= v[i - 1]){
            cnt++;
            while(i<n && v[i] <= v[i - 1]) i++;
        }
        if (i< n && v[i] >= v[i - 1]){
            cnt++;
            while(i< n && v[i] >= v[i - 1]) i++;
        }
    }
    cout << cnt << endl;
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