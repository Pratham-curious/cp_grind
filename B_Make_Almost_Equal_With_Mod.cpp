#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

bool check(vector<ll> &v, ll k)
{
    map<ll, ll> mp;
    for (auto it : v)
    {
        mp[it % k]++;
    }
    return mp.size() == 2;
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
        ll k = 2;
        while (!check(v, k))
            k *= 2;
        cout << k << endl;
    }
    return 0;
}