class Solution {
public:
    
    void unionTwo(int x, int y,vector<int>& par,vector<int>& size){
        int parx = findParent(x,par);
        int pary = findParent(y,par);
        if(parx == pary) return;
        if(size[parx] >= size[pary]){
            size[parx]+=size[pary];
            par[pary] = parx;
        }
        else{
            size[pary]+=size[parx];
            par[parx] = pary;
        }
    }
    int findParent(int x,vector<int>& par){ // path compression
        if(par[x] != x){
            return par[x] = findParent(par[x],par);
        }
        return x;
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> par(c+1,0);
        vector<int> siz(c+1,0);
        for(int i=1;i<=c;i++) par[i] = i;
        map<int,set<int>> mp;
        vector<int> ans;
        for(int i=0;i<connections.size();i++){
            int  u = connections[i][0], v = connections[i][1];
            unionTwo(u,v,par,siz);
        }
        for(int i = 1; i <= c; i++) {
            int root = findParent(i, par);  
            mp[root].insert(i);
        }
        vector<bool> online(c+1,true);
        for(auto it : queries){
            int type = it[0], val = it[1];
            if(type == 1){
                if(online[val]) ans.push_back(val);
                else if(!mp[par[val]].empty()) ans.push_back(*(mp[par[val]]).begin());
                else ans.push_back(-1);
            }
            else{
                if(online[val]){
                    online[val]=false;
                    mp[par[val]].erase(val);
                }
            }
        }
        return ans;
        
    }
};