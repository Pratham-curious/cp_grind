#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 0;
    cin >> t;

    while (t--)
    {
        ll n = 0;
        cin >> n;
        vector<ll> v(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ll curr = v[i], idx = i;
            ll rem = curr - (idx % curr);
            for (int j = rem; j <= n; j += curr)
            {
                if (j != idx && curr * v[j] == idx + j)
                    ans++;
            }
        }
        cout << ans / 2 << endl;
    }
    return 0;
}