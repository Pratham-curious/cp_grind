class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, 0), pref(n, 0);
        set<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            auto it = st.upper_bound({nums[i], i});
            if (it == st.end()) {
                pref[i] = i;
            } else {
                pref[i] = pref[(*it).second];
            }
            st.insert({nums[i], i});
        }
        int mini = n;
        vector<int> ans(n, 0);
        while (!st.empty()) {
            auto [curr, idx] = *st.rbegin();
            st.erase(*st.rbegin());
            if (!vis[idx]) {
                ans[idx] = curr;
                for (int i = idx; i < n; i++) {
                    if (vis[i])
                        break;
                    vis[i] = 1;
                    ans[i] = curr;
                    mini = min(mini, pref[i]);
                }
                int start = idx;
                while (start >= mini) {
                    vis[start] = 1;
                    ans[start] = curr;
                    mini = min(mini, pref[start]);
                    start--;
                }
            }
        }
        return ans;
    }
};