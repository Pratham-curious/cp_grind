class Solution {
public:
    vector<int> cal(vector<vector<int>>& edge){
        int n = edge.size()+1;
        vector<vector<int>> adj(n);

        for(int i=0;i<n-1;i++){
            adj[edge[i][0]].push_back(edge[i][1]);
            adj[edge[i][1]].push_back(edge[i][0]);
        }
        vector<int> col(n,-1);
        queue<int> qu;
        qu.push(0);
        col[0]=0;
        while(!qu.empty()){
            int top = qu.front();
            qu.pop();
            for(auto it : adj[top]){
                if(col[it] == -1){
                    col[it]=1-col[top];
                    qu.push(it);
                }
            }
        }
        return col;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> tree1 = cal(edges1);
        vector<int> tree2 = cal(edges2);
        int odd2 = 0, even2 = 0;
        for(int i=0;i<tree2.size();i++){
            if(tree2[i]==1) even2++;
            else odd2++;
        }
        int maxi = max(even2,odd2);
        int odd1= 0, even1 = 0;
        for(int i=0;i<tree1.size();i++){
            if(tree1[i]==1) even1++;
            else odd1++;
        }
        vector<int> ans(tree1.size(),0);
        for(int i=0;i<tree1.size();i++){
            if(tree1[i]==1) ans[i] = even1+maxi;
            else ans[i] = odd1+maxi;
        }
        return ans;
    }
};