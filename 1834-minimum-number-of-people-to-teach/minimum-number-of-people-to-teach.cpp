class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        vector<vector<int>> left;
        for (int i = 0; i < friendships.size(); i++) {
            int u = friendships[i][0], v = friendships[i][1];
            u--, v--;
            bool present = false;
            for (auto it : languages[u]) {
                for (auto other : languages[v]) {
                    if (it == other) {
                        present = true;
                        break;
                    }
                }
                if (present)
                    break;
            }
            if (!present) {
                left.push_back({u, v});
            }
        }
        int ans = 501;
        for (int i = 1; i <= 500; i++) {
            vector<bool> vis(501, false);
            int cnt = 0;
            for (auto it : left) {
                int u = it[0], v = it[1];
                if (vis[u] && vis[v])
                    continue;
                bool present = false;
                if (!vis[u]) {
                    for (auto lang : languages[u]) {
                        if (lang == i) {
                            present = true;
                            vis[u] = true;
                            break;
                        }
                    }
                    if (!present) {
                        cnt++;
                        vis[u] = true;
                    }
                }
                present = false;
                if (!vis[v]) {
                    for (auto lang : languages[v]) {
                        if (lang == i) {
                            present = true;
                            vis[v] = true;
                            break;
                        }
                    }
                    if (!present) {
                        cnt++;
                        vis[v] = true;
                    }
                }
            }
            ans = min(cnt,ans);
        }
        return ans == 501 ? 0 : ans;
    }
};