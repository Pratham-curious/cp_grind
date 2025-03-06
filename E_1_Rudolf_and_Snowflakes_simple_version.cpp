#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 2; i * i <= n - 1; i++)
    {
        ll temp = n - 1;
        if (temp % i == 0)
        {
            ll r = i;
            bool err = false;
            ll cnt = 1;
            while (temp != 0)
            {
                if (temp % r != 0)
                {
                    err = true;
                    break;
                }
                temp /= r;
                temp--;
                cnt++;
            }
            if (!err && cnt > 2)
            {
                cout << "YES" << endl;
                return;
            }
            if (temp / i != i)
            {
                ll r = i;
                bool err = false;
                ll cnt = 1;
                while (temp != 0)
                {
                    if (temp % r != 0)
                    {
                        err = true;
                        break;
                    }
                    temp /= r;
                    temp--;
                    cnt++;
                }
                if (!err && cnt>2)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
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