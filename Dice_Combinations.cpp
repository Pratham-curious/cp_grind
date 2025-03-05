#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const ll mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, 0);
    for (int i = 1; i <= 6; i++)
        dp[i] = 1;
    for (ll i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (ll j = 0; j <= 6; j++)
        {
            if (i - j > 0)
                sum = (sum + dp[i - j]) % mod;
        }
        dp[i] = sum;
    }
    cout << dp[n] << endl;
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