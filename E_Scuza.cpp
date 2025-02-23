#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll search(vector<ll> &v, ll &tar)
{
    ll low = 0, high = v.size() - 1;
    ll ans = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (v[mid] <= tar)
        {
            ans = mid;
            low = mid + 1;
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
        ll n = 0, q;
        cin >> n >> q;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<ll> pref(n + 1, 0);
        for (int i = 1; i < n + 1; i++)
        {
            pref[i] = pref[i - 1] + v[i - 1];
        }
        vector<ll> maxi(n + 1, 0);
        for (int i = 1; i < n + 1; i++)
        {
            maxi[i] = max(maxi[i - 1], v[i - 1]);
        }
        while (q--)
        {
            ll ask = 0;
            cin >> ask;
            ll index = search(maxi, ask);
            cout << pref[index] << " ";
        }
        cout << endl;
    }
    return 0;
}