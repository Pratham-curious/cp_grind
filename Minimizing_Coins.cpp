#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> dp(1e6 + 1, INT_MAX);
    for (auto it : v)
        dp[it] = 1;
    for (ll i = 1; i <= x; i++)
    {
        for (auto it : v)
        {
            if (i - it > 0)
                dp[i] = min(dp[i], 1 + dp[i - it]);
        }
    }
    if (dp[x] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dp[x] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tt = 1;
    // Uncomment the next line to read multiple test cases.
    // cin >> tt;
    for (ll t = 1; t <= tt; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}