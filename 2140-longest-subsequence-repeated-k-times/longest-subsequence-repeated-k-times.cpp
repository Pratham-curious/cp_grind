class Solution {
public:
    string ans = "";
    void check(string& temp, string& s, int& k) {
        int len = temp.size();
        int idx = -1;
        for (int i = 1; i <= len; i++) {
            vector<int> count(i, 0);
            int j = 0;
            bool fnd = false;
            for (auto it : s) {
                j %= i;
                if(temp[j] == it){
                    count[j]++;
                    if(count[j]==k && j == i-1){
                        idx = i;
                        fnd = true;
                        break;
                    }
                    j++;
                }
            }
            if(!fnd) break;
        }
        if (ans.size() <= idx)
            ans = max(ans, temp.substr(0, idx));
    }
    void cal(string& temp, vector<bool>& vis, vector<char>& v, int len,
             string& s, int& k) {
        int n = vis.size();
        if (len == n) {
            check(temp, s, k);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                temp += v[i];
                cal(temp, vis, v, len + 1, s, k);
                temp.pop_back();
                vis[i] = false;
            }
        }
        return;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        map<char, int> mp;
        vector<char> v;
        int n = s.size();
        for (auto it : s)
            mp[it]++;
        int len = n / k;
        for (auto it : mp) {
            if (it.second >= k) {
                int m = it.second / k;
                while (m--) {
                    v.push_back(it.first);
                }
            }
        }
        int m = v.size();

        vector<bool> vis(m, false);
        string temp = "";
        cal(temp, vis, v, 0, s, k);

        return ans;
    }
};