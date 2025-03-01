#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll r, c, n, p;
    cin >> r >> c >> n >> p;
    vector<vector<ll>> v(r, vector<ll>(c, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> v[i][j];
        }
    }
    set<ll> st;
    ll dist = p - 1;
    queue<pair<ll, ll>> qu;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (v[i][j] == 1)
                qu.push({i, j});
        }
    }
    vector<pair<ll, ll>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    ll next = 2;
    while (!qu.empty())
    {
        ll x = qu.front().first, y = qu.front().second;
        qu.pop();
        for (auto it : directions)
        {
            ll nx = x + it.first, ny = y + it.second;
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && v[nx][ny] != 0)
            {
                if (v[nx][ny] == next && next != p + 1)
                {
                    next++;
                    qu.push({nx, ny});
                }
                if (v[nx][ny] + dist <= n)
                    st.insert(v[nx][ny] + dist);
            }
        }
        dist--;
    }
    cout << st.size() << "/" << n - 1 << endl;

    return 0;
}