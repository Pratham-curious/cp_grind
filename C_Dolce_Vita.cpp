#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll search(vector<ll> &v, ll &x)
{
    ll low = 0, high = v.size() - 1;
    ll ans = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (v[mid] <= x)
        {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 0;
    cin >> t;

    while (t--)
    {
        ll n = 0, x;
        cin >> n >> x;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<ll> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + v[i - 1];
        ll ans = 0;
        ll val = search(prefix, x);
        ll last = 0;
        for (int i = val; i > 0; i--)
        {
            ll upper = x - prefix[i] - last * i;
            if (upper < 0)
                continue;
            ll curr = upper / i + 1;
            ans += curr * i;
            last += curr;
        }
        cout << ans << endl;
    }
    return 0;
}