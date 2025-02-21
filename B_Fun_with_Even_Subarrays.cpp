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
        ll final = v[n - 1];
        ll i = n - 1, last = 0, cnt = 0;
        while (i >= 0)
        {
            while (v[i] == final)
            {
                i--;
                last++;
            }
            if (i >= 0)
            {
                cnt++;
                i -= last;
                last *= 2;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}