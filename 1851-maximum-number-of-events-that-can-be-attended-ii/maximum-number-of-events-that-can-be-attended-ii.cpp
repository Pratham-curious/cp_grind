class Solution {
public:
    #define ll long long
    int maxValue(vector<vector<int>>& events, int k) {
        map<ll,vector<pair<ll,ll>>> store;
        ll maxi = 0;
        for(int i=0;i<events.size();i++){
            store[events[i][1]].push_back({events[i][0],events[i][2]});
        }
        store[0] = {{0,0}};
        unordered_map<ll,map<ll,ll>> val;
        val[0][0] = 0;
        for(int i=1;i<=k;i++){
            val[0][i] = LLONG_MIN;
        }
        ll ans = 0;
        for(int i=1;i<=k;i++){
            for(auto end = store.begin() ; end != store.end();end++){
                if(end->first == 0) continue;
                auto pre = prev(end);
                val[end->first][i] = val[pre->first][i];
                for(auto it : end->second){
                    auto idx = store.lower_bound(it.first);
                    idx = prev(idx);
                    val[end->first][i] = max(val[end->first][i] ,it.second+val[idx->first][i-1]);
                    ans = max(ans,val[end->first][i]);
                }
            }
        }

        return ans;
    }
};