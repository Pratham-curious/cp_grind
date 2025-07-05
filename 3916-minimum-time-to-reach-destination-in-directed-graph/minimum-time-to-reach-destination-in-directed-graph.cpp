class Solution {
public:
 #define ll long long
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,pair<ll,ll>>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],{edges[i][2],edges[i][3]}});
        }
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> qu;
        qu.push({0ll,0});
        vector<ll> time(n,LLONG_MAX);
        time[0] = 0;
        while(!qu.empty()){
            auto curr = qu.top();
            qu.pop();
            int node = curr.second;
            ll tm = curr.first;

            if(time[node]< tm) continue;

            for(auto it : adj[node]){
                int v = it.first;
                ll start = it.second.first, end = it.second.second;
                if(tm > end) continue;
                if(time[v] > max(tm,start)+1){
                    qu.push({max(tm,start)+1,v});
                    time[v] = max(tm,start)+1;
                }
            }
        }
        if(time[n-1] == LLONG_MAX) return -1;
        return time[n-1];
    }
};