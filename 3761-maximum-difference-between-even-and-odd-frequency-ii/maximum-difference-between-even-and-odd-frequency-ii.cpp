class Solution {
public:
    int maxDifference(string s, int k) {
        int ans = INT_MIN;
        int n = s.size();
        for (int a = 0; a <= 4; a++) {
            for (int b = 0; b <= 4; b++) {
                if (a == b)
                    continue;
                // a -> i, b->j ; a --> odd, b--> even
                vector<int> up(n, 0), down(n, 0);
                up[0] = (s[0] - '0') == a;
                down[0] = (s[0] - '0') == b;
                for (int idx = 1; idx < n; idx++) {
                    up[idx] = up[idx - 1] + ((s[idx] - '0') == a);
                    down[idx] = down[idx - 1] + ((s[idx] - '0') == b);
                }

                int val = INT_MIN;
                unordered_map<int, pair<int, int>> mp;
                // 0 -> even, even : 1 -> even,odd : 2-> odd,even : 3-> odd,odd
                for (int i = k - 1; i < n; i++) {
                    if (i - k < 0) {
                        if (up[i] % 2 != 0 && down[i] % 2 == 0 && down[i] > 0) {
                            val = max(val, up[i] - down[i]);
                        }
                    } else {
                        int j = i - k;
                        int num1 = (up[j] % 2) * 2 + down[j] % 2;
                        int curr = (up[i] % 2) * 2 + down[i] % 2;
                        
                        if (curr == 2 && down[i] > 0)
                            val = max(val, up[i] - down[i]);

                        if (mp.find(num1) != mp.end()) {
                            if (mp[num1].first > up[j] - down[j])
                                mp[num1] = {up[j] - down[j], j};
                            else if (mp[num1].first == up[j] - down[j]) {
                                mp[num1].second =
                                    down[mp[num1].second] >= down[j]
                                        ? j
                                        : mp[num1].second;
                            }
                        } else
                            mp[num1] = {up[j] - down[j], j};

                        int rem = (2 + curr) % 4;
                        if (mp.find(rem) != mp.end()) {
                            if (down[i] - down[mp[rem].second] > 0)
                                val = max(val, up[i] - down[i] - mp[rem].first);
                        }
                    }
                }
                ans = max(val, ans);
            }
        }
        return ans;
    }
};