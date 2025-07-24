class Solution {
public:
    int cal(int curr, int parent, vector<int>& nums, vector<vector<int>>& adj, vector<int>& comp ) {
        for (auto nextNode : adj[curr]) {
            if (nextNode != parent) {
                int val = cal(nextNode,curr,nums,adj,comp);
                nums[curr] ^= val;
                comp.push_back(val);
            }
        }
        return nums[curr];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        
        int mini = INT_MAX;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            vector<int> comp1,comp2;
            vector<int> v1 = nums,v2 = nums;
            int valU = cal(u,v,v1,adj,comp1);
            int valV = cal(v,u,v2,adj,comp2);
           

            for (auto it : comp1) {
                int a = it;
                int b = valU ^ it;
                int c = valV;
                int up = max({a, b, c});
                int low = min({a, b, c});
                mini = min(mini, up - low);
            }
            for (auto it : comp2) {
                int a = it;
                int b = valV ^ it;
                int c = valU;
                int up = max({a, b, c});
                int low = min({a, b, c});
                mini = min(mini, up - low);
            }
        }
        return mini;
    }
};
