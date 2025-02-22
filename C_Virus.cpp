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
        ll n = 0, m;
        cin >> n >> m;
        vector<ll> v(m);
        for (int i = 0; i < m; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        priority_queue<ll> qu;
        for (int i = 1; i < m; i++)
        {
            qu.push(v[i] - v[i - 1] - 1);
        }
        qu.push(n - v[m - 1] + v[0] - 1);
        ll sec = 0, save = 0;
        while (!qu.empty())
        {
            ll gap = qu.top();
            qu.pop();
            gap -= 2 * sec;
            if (gap <= 0)
                break;
            save++;
            sec++;
            gap -= 2;
            if (gap <= 0)
                break;
            sec++;
            save += gap;
        }
        cout << n - save << endl;
    }
    return 0;
}