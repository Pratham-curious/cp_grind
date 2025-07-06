
class Solution {
public:
 
#define ll long long
    void unionTwo(int x, int y, vector<int>& par, vector<int>& size) {
        ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        int parx = findParent(x, par);
        int pary = findParent(y, par);
        if (parx == pary)
            return;
        if (size[parx] >= size[pary]) {
            size[parx] += size[pary];
            par[pary] = parx;
        } else {
            size[pary] += size[parx];
            par[parx] = pary;
        }
    }
    int findParent(int x, vector<int>& par) {
        if (par[x] != x) {
            return par[x] = findParent(par[x], par);
        }
        return x;
    }
    bool check(ll& mid, vector<vector<pair<int, int>>>& adj, int& k, int& n) {
        vector<int> par(n, 0), size(n, 1);
        for (int i = 0; i < n; i++)
            par[i] = i;

        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                if(it.second > mid) unionTwo(i,it.first,par,size);
            }
        }
        set<int> st;
        for(int i=0;i<n;i++){
            int root = findParent(i,par);
            st.insert(root);
        }
        return st.size() >= k;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        vector<vector<pair<int, int>>> adj(n);
        ll high = 0;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], tm = edges[i][2];
            adj[u].push_back({v, tm});
            adj[v].push_back({u, tm});
            high = max(high, (ll)tm);
        }
        ll low = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (check(mid, adj, k, n))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};