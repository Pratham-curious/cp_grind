class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        vector<vector<int>> adj(26);
        for (int i = 0; i < n; i++) {
            adj[s2[i] - 'a'].push_back(s1[i] - 'a');
            adj[s1[i] - 'a'].push_back(s2[i] - 'a');
        }
        vector<int> vis(26, -1);
        for (int i = 0; i < 26; i++) {
            if (vis[i] == -1) {
                vis[i] = i;
                queue<int> qu;
                qu.push(i);
                while (!qu.empty()) {
                    int top = qu.front();
                    qu.pop();
                    for (auto it : adj[top]) {
                        if (vis[it] == -1) {
                            qu.push(it);
                            vis[it] = i;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < baseStr.size(); i++) {
            int ch = baseStr[i]-'a';
            if(vis[ch] != -1) baseStr[i] = vis[ch] + 'a';
        }
        return baseStr;
    }
};