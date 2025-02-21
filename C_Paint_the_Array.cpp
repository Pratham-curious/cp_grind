#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

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
        ll eve = 0, odd = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 1)
                odd = gcd(odd, v[i]);
            else
                eve = gcd(eve, v[i]);
        }
        bool found = false;
        for (int i = 1; i < n; i += 2)
        {
            if (v[i] % eve == 0)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << eve << endl;
            continue;
        }
        found = false;
        for (int i = 0; i < n; i += 2)
        {
            if (v[i] % odd == 0)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << odd << endl;
            continue;
        }

        cout << 0 << endl;
    }
    return 0;
}