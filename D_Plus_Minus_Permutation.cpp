#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define ll long long
#define pb push_back

ll sum(ll n)
{
    return (n * (n + 1)) / 2;
}

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
        ll n = 0, x, y;
        cin >> n >> x >> y;
        ll com = (x * y) / gcd(x, y);
        ll a = n / x;
        ll b = n / y;
        ll c = n / com;
        ll top = a - c;
        ll low = b - c;
        cout << sum(n) - sum(low) - sum(n - top) << endl;
    }
    return 0;
}