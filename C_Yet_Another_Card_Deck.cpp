#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n = 0, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> a(51, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        a[v[i]] = i + 1;
    }
    while (q--)
    {
        ll ask;
        cin >> ask;
        cout << a[ask] << " ";
        ll curr = a[ask];
        for (int i = 1; i < 51; i++)
        {
            if (a[i] < curr)
                a[i]++;
        }
        a[ask] = 1;
    }
    cout << endl;

    return 0;
}