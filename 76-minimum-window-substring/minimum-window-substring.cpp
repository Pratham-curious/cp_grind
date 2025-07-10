class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mp;
        for (auto it : t)
            mp[it]++;

        int n = s.size();
        int left = 0;
        int cnt = 0;
        int l = 0, len = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    cnt++;
            }
            if (cnt == mp.size()) {
                if (i - left + 1 < len) {
                    len = i -left +1;
                    l = left;
                }
                while (cnt == mp.size()) {
                    if (i - left + 1 < len) {
                        len = i- left + 1;
                        l = left;
                    }
                    if (mp.find(s[left]) != mp.end()) {
                        mp[s[left]]++;
                        if (mp[s[left]] == 1) {
                            cnt--;
                            left++;
                            break;
                        }
                    }
                    left++;
                }
            }
        }
        if (len == INT_MAX)
            return "";
        return s.substr(l, len);
    }
};