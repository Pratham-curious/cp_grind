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
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        map<ll, ll> mp;
        for (auto it : v)
            mp[it]++;
        ll last = -1, ans = 0, maxi = 0;
        for (auto it : mp)
        {
            if (it.first == last)
            {
                if (it.second >= maxi)
                {
                    ans += it.second - maxi;
                    maxi = it.second;
                }
                else
                {
                    maxi = it.second;
                }
                last++;
            }
            else
            {
                last = it.first + 1;
                maxi = it.second;
                ans += maxi;
            }
        }

        cout << ans << endl;
    }
    return 0;
}