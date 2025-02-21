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
        ll val = -1;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != i)
            {
                if (val == -1)
                    val = i;
                else
                    val &= i;
            }
        }
        cout << val << endl;
    }
    return 0;
}