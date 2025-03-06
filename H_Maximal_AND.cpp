#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> dig(31, 0);
    for (auto it : v)
    {
        for (int i = 30; i >= 0; i--)
        {
            ll val = (it & (1ll << i)) > 0;
            dig[i] += val;
        }
    }
    vector<ll> res(31,0);
    for(int i=30;i>=0;i--){
        if(dig[i]<n){
            if(n<=k+dig[i]){
                res[i]=1;
                k = k+dig[i]-n;
            }
        }
        else res[i]=1;
    }
    ll cal = 0;
    for(int i=0;i<=30;i++){
        if(res[i]==1) cal += pow(2,i);
    }
    cout<<cal<<endl;
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