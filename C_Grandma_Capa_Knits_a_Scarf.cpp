#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {
    ll n;
    cin >> n;
    string s;
    cin>>s;
    vector<ll> v(26,INT_MAX);
    for(int i=0;i<26;i++){
        char check = 'a'+i;
        bool err = false;
        ll fnt = 0, bck = n-1;
        ll skip = 0;
        while(fnt <= bck){
            if(s[fnt]==s[bck]){
                fnt++;
                bck--;
            }
            else{
                if(s[fnt]==check){
                    skip++;
                    fnt++;
                }
                else if(s[bck]==check){
                    skip++;
                    bck--;
                }
                else{
                    err = true;
                    break;
                }

            }
        }
        if(!err) v[i]=skip;
    }
    sort(v.begin(),v.end());
    if(v[0]==INT_MAX) cout<<-1<<endl;
    else cout<<v[0]<<endl;


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tt = 1;
    // Uncomment the next line to read multiple test cases.
    cin >> tt;
    for (ll t = 1; t <= tt; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}