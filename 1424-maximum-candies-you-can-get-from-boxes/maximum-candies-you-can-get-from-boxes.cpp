class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n = status.size();
        vector<int> vis(n, false), enter(n, false);

        queue<int> qu;
        for (auto it : initialBoxes) {
            vis[it] = true;
            if(status[it])qu.push(it);
        }

        while (!qu.empty()) {
            int top = qu.front();
            qu.pop();
            if (enter[top])
                continue;
            enter[top]=true;
            for (auto key : keys[top]) {
                if (status[key] == 0) {
                    status[key] = 1;
                    if (vis[key] == true)
                        qu.push(key);
                }
            }
            for (auto it : containedBoxes[top]){
                vis[it]=true;
                if(status[it] && !enter[it]) qu.push(it);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(enter[i]) ans+=candies[i];
        }
        return ans;
    }
};