class Solution {
public:
    vector<int> cal(vector<vector<int>>& edges1, int k) {
        int n = edges1.size() + 1;
        vector<vector<int>> tree1(n);
        for (int i = 0; i < n - 1; i++) {
            tree1[edges1[i][0]].push_back(edges1[i][1]);
            tree1[edges1[i][1]].push_back(edges1[i][0]);
        }

        vector<int> dist1(n, 0);
        for (int i = 0; i < n; i++) {
            vector<bool> visit(n, false);
            queue<int> qu;
            qu.push(i);
            visit[i] = true;
            int cnt = 0;

            while (!qu.empty()) {
                int size = qu.size();
                if (cnt > k) {
                    break;
                }
                dist1[i] += size;
                for (int j = 0; j < size; j++) {
                    int top = qu.front(); qu.pop();
                    for (auto it : tree1[top]) {
                        if (!visit[it]) {
                            qu.push(it);
                            visit[it] = true;
                        }
                    }
                }
                cnt++;
            }
        }

        return dist1;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        vector<int> dist1 = cal(edges1, k);
        vector<int> dist2 = cal(edges2, k - 1);

        int maxi = 0;
        for (auto it : dist2) maxi = max(maxi, it);

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = dist1[i] + maxi;
        }

        return ans;
    }
};
