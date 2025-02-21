#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const ll mod = 1e9 + 7;

ll mod_inv(ll n)
{
    ll res = 1, pow = mod - 2;
    while (pow)
    {
        if (pow & 1)
            res = (res * n) % mod;
        n = (n * n) % mod;
        pow >>= 1;
    }
    return res;
}

ll cal(ll n)
{
    return n % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    ll inv6 = mod_inv(6); // Precompute 1/6 mod (1e9 + 7)

    while (t--)
    {
        ll n;
        cin >> n;

        ll term1 = cal(2022 * n % mod * (n - 1) % mod * (4 * n + 1) % mod * inv6 % mod);
        ll term2 = cal(2022 * n % mod * n % mod);

        ll ans = cal(term1 + term2);

        cout << ans << '\n';
    }

    return 0;
}
