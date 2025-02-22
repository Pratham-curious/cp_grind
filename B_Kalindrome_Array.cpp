#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

bool make(vector<ll> &v, ll i, ll j, ll val)
{
    bool err = true;
    while (i < j)
    {
        if (v[i] == val)
            i++;
        else if (v[j] == val)
            j--;
        else if (v[i] != v[j])
        {
            err = false;
            break;
        }
        else
            i++, j--;
    }
    return err;
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
        ll i = 0;
        bool enter = false;
        bool val = false;
        for (int i = 0; i < n / 2; i++)
        {
            if (v[i] == v[n - 1 - i])
                continue;
            else
            {
                enter = true;
                val = make(v, i, n - 1 - i, v[i]) || make(v, i, n - 1 - i, v[n - 1 - i]);
                break;
            }
        }
        if (!enter)
            cout << "YES" << endl;
        else if (val)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}