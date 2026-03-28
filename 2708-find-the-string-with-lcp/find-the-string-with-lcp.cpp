class Solution {
public:
    int findparent(int a, vector<int>& parent) {
        if (a == parent[a])
            return a;

        return parent[a] = findparent(parent[a], parent);
    }

    void uni(int a, int b, vector<int>& parent, vector<int>& sz) {
        int pa = findparent(a, parent);
        int pb = findparent(b, parent);
        if (pa == pb)
            return;
        else if (sz[pa] >= sz[pb]) {
            parent[pb] = pa;
            sz[pa] += sz[pb];
        } else {
            parent[pa] = pb;
            sz[pb] += sz[pa];
        }
    }
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        vector<char> word(n);
        vector<int> v(n, -1), parent(n, -1), sz(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                if (lcp[i][j] == 0)
                    continue;
                if (v[j] != -1)
                    uni(v[j], i, parent, sz);
                v[j] = i;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] != lcp[j][i])
                    return "";
                if (i == j && lcp[i][j] != n - i)
                    return "";
                if (lcp[i][j] > n - i)
                    return "";

              
                    int pa = findparent(v[i], parent);
                    int pb = findparent(v[j], parent);
                    if (pa == pb) {
                        if (lcp[i][j] == 0)
                            return "";
                        if (i + 1 < n && j + 1 < n) {
                            if (lcp[i][j] != 1 + lcp[i + 1][j + 1])
                                return "";
                        }
                    }
                
            }
        }

        unordered_map<int, char> mp;
        int j = 0;

        for (int i = 0; i < n; i++) {
            if (v[i] == -1) {
                if (j >= 26)
                    return "";
                word[i] = 'a' + j;
                j++;
            } else {
                int pa = findparent(v[i], parent);
                if (mp.find(pa) != mp.end()) {
                    word[i] = 'a' + mp[pa];
                } else {
                    if (j >= 26)
                        return "";
                    mp[pa] = j;
                    word[i] = 'a' + mp[pa];
                    j++;
                }
            }
        }
        string ans = "";
        for (auto it : word)
            ans += it;
        return ans;
    }
};