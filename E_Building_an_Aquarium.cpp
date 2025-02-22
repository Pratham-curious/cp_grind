#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

bool check(vector<ll> &v, ll &mid, ll &x)
{
    ll sum = 0;
    for (auto it : v)
    {
        sum += max((ll)0, mid - it);
        if (sum > x)
            return false;
    }
    return sum <= x;
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
        ll low = 1, high = 1e12;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (check(v, mid, x))
                low = mid + 1;
            else
                high = mid - 1;
        }
        cout << high << endl;
    }
    return 0;
}