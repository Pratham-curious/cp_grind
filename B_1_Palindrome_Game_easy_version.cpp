#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt = 0;
    for (auto it : s)
        cnt += (it == '0');
    if (cnt == 1)
    {
        cout << "BOB" << endl;
        return;
    }

    if (cnt % 2 == 0)
    {
        
            cout << "BOB" << endl;
    }
    else
    {
        cnt--;
    
            cout << "ALICE" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tt = 1;
    // Uncomment the next line to read multiple test cases.
    cin >> tt;
    for (ll t = 1; t <= tt; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}