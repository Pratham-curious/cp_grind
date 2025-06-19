// User function Template for C++

class Solution {
    #define ll long long
    #define pb push_back
public:
    class DSU {
        public:
            vector<int> parent, size;
            
            DSU(int n) {
                parent.resize(n+1);
                size.resize(n+1, 1);
                for (int i = 0; i <= n; ++i)
                    parent[i] = i;
            }
            
            int findpar(int x) {
                if (parent[x] != x)
                    parent[x] = findpar(parent[x]);
                return parent[x];
            }
            
            void unite(int x, int y) {
                int px = findpar(x);
                int py = findpar(y);
                if (px == py) return;
                if (size[px] < size[py])
                    swap(px, py);
                parent[py] = px;
                size[px] += size[py];
            }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<string,int> nameto;
        int n = accounts.size();
        int curr = 0;
        for(int i=0;i<n;i++){
            int m = accounts[i].size();
            for(int j=1;j<m;j++){
                if(nameto.find(accounts[i][j])==nameto.end()){
                    nameto[accounts[i][j]]=curr;
                    curr++;
                }
            }
        }
        DSU ds(curr);
        for(int i=0;i<n;i++){
            int m = accounts[i].size();
            for(int j=1;j<m;j++){
                ds.unite(nameto[accounts[i][1]],nameto[accounts[i][j]]);
            }
        }
        vector<bool> vis(curr,false);
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            int par = ds.findpar(nameto[accounts[i][1]]);
            if(!vis[par]){
                vis[par] = true;
                vector<string> curr = {accounts[i][0]};
                set<string> st;
                for(int i=0;i<n;i++){
                    for(int j = 1;j<accounts[i].size();j++){
                        if(ds.findpar(nameto[accounts[i][j]]) == par){
                            st.insert(accounts[i][j]);
                        }
                    }
                }
                while(!st.empty()){
                    curr.push_back(*st.begin());
                    st.erase(*st.begin());
                }
                ans.push_back(curr);
            }
        }
        
        return ans;
        
    }
};
