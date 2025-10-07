class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        set<int> zro;
        unordered_map<int,int> mp;

        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                if (!mp.empty() && mp.find(rains[i]) != mp.end()) {
                    if (zro.empty())
                        return vector<int>{};
                    auto it = zro.lower_bound(mp[rains[i]]);
                    if(it == zro.end()){
                         return vector<int>{};
                    }
                    int idx = *it;
                    zro.erase(*it);
                    ans[idx] = rains[i];
                    mp[rains[i]] = i;
                } else {
                    mp[rains[i]] = i;
                }
            } else {
                zro.insert(i);
            }
        }
        while (!zro.empty()) {
            int idx = *zro.begin();
            zro.erase(zro.begin());
            ans[idx] = 1;
        }
        return ans;
    }
};