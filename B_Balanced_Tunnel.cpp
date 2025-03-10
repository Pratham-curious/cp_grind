#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<ll> rm(n + 1, 0);
    int j = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (rm[a[i]] != -1)
        {
            if (j < n && a[i] == b[j])
            {
                j++;
                continue;
            }
            while (j < n && a[i] != b[j])
            {
                rm[b[j]] = -1;
                j++;
            }
            j++;
        }
    }
    for(auto it : rm) ans+=(it==-1);
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tt = 1;
    // Uncomment the next line to read multiple test cases.
   // cin >> tt;
    for (ll t = 1; t <= tt; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}