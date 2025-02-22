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
        ll m = (n * (n - 1)) / 2;
        vector<ll> v(m);
        for (int i = 0; i < m; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<ll> ans;
        ll i = 0;
        ll jmp = n - 1;
        while (i < m)
        {
            ans.pb(v[i]);
            i += jmp;
            jmp--;
        }
        ans.pb(ans.back());
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}