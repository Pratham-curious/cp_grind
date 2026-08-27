class Solution {
public:
/*
Observation : 

1.




*/
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        set<pair<int,int>> st;
        vector<vector<int>> adj(n);

        queue<int> qu;
        vector<int> deg(n,0);

        for(auto it : edges){
            st.insert({it[0],it[1]});
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            deg[it[0]]++;
            deg[it[1]]++;;
        }

        vector<int> ans(n,0),up(n,0);

        for(int i=0;i<n;i++){
            if(deg[i] == 1){
                qu.push(i);
            }
        }

        int idx = -1;

        while(!qu.empty()){
            int curr = qu.front();
            qu.pop();
            deg[curr] = 0;
            idx = curr;

            for(auto it : adj[curr]){
                if(deg[it] > 0){
                    deg[it]--;
                    up[it] += up[curr];
                    if(st.find({curr,it}) != st.end()){
                        up[it]++;
                    }
                    if(deg[it] == 1){
                        qu.push(it);
                    }
                }
            }
        }

        ans[idx] = up[idx];
        qu.push(idx);

        while(!qu.empty()){
            int curr = qu.front();
            deg[curr] = -1;
            qu.pop();

            for(auto it : adj[curr]){
                if(deg[it] == 0 ){
                    if(st.find({curr,it}) != st.end()){
                        ans[it] = ans[curr] + 1;
                    }
                    else{
                        ans[it] = ans[curr] - 1;
                    }
                    qu.push(it);
                }
            }
        }
        return ans;

    }
};