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
        if (v[n - 1] < v[n - 2])
        {
            cout << -1 << endl;
            continue;
        }
        bool err = false;
        if (v[n - 1] < 0)
        {
            for (int i = n - 3; i >= 0; i--)
            {
                if (v[i] > v[i + 1])
                {
                    err = true;
                    break;
                }
            }
            if (err)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
            continue;
        }
        cout << n - 2 << endl;
        for (int i = n - 3; i >= 0; i--)
        {
            cout << i + 1 << " " << n - 1 << " " << n << endl;
        }
    }
    return 0;
}