class Solution {
public:
    bool check(vector<int> deg, vector<vector<int>>& adj){
        int n = deg.size();
        vector<bool> visit(n,false);
        queue<int> qu;
        for(int i=0;i<n;i++){
            if(deg[i]==0){ 
                visit[i] = true;
                qu.push(i);
            }
        }
        while(!qu.empty()){
            int top = qu.front();
            qu.pop();
            for(auto it : adj[top]){
                deg[it]--;
                if(deg[it]==0){
                    visit[it]=true;
                    qu.push(it);
                }
            }
        }
        for(auto it : visit) if(!it) return true;
        return false;
    }
    int cal(int curr,vector<vector<int>>& adj,vector<int>& dp,string& s,int& color){
        if(dp[curr]!=-1) return dp[curr];
        int ans = 0;
        for(auto it : adj[curr]){
            ans = max(ans,cal(it,adj,dp,s,color));
        }
        return dp[curr] = (s[curr]-'a' == color) + ans;

    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> deg(n,0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            deg[it[1]]++;
        }
        if(check(deg,adj)) return -1;
        vector<int> alp(26,0);
        for(int i=0;i<26;i++){
            vector<int> dp(n,-1);
            for(int j=0;j<n;j++){
                if(deg[j]==0){
                    alp[i] = max(alp[i],cal(j,adj,dp,colors,i));
                }
            }
        }
        int ans = 0;
        for(auto it : alp) ans = max(ans,it);
        return ans;
    }

};