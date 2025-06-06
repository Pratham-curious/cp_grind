class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> vis(n, false);
        set<pair<char, int>> st;
        set<int> left;
        for (int i = 0; i < n; i++)
            st.insert({s[i], i});
        string ans;
        while (!st.empty()) {
            auto [ch, idx] = *st.begin();
            st.erase(*st.begin());
            if (!left.empty() && idx <= *left.rbegin()) {
                while (!left.empty() && s[*left.rbegin()] <= ch) {

                    ans += s[*left.rbegin()];
                    vis[*left.rbegin()] = true;
                    left.erase(*left.rbegin());
                }
            }
            if (!vis[idx]) {
                ans += ch;
                vis[idx] = true;
                for (int i = idx-1; i >= 0; i--) {
                    if (!vis[i]) {
                        vis[i] = true;
                        left.insert(i);
                    }
                    else break;
                }
            }
        }
        while (!left.empty()) {
            ans += s[*left.rbegin()];
            left.erase(*left.rbegin());
        }
        return ans;
    }
};