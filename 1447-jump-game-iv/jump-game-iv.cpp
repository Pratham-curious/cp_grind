class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i);



        vector<bool> vis(n,false);
        vis[0] = true;
        vis[1] = true;

        queue<int> qu;
        int cnt = 1;
        if(arr[1] != arr[0]) qu.push(1);
        for(auto it : mp[arr[0]]) {
            vis[it] = true;
            if(it != 0 ) qu.push(it);
        }
        
        set<int> st;
        st.insert(arr[0]);

        while(!qu.empty()){
            int sz = qu.size();

            while(sz--){
                int curr = qu.front();
                qu.pop();
                cout<<curr<<endl;

                if(curr == n-1) return cnt;

                if(st.find(arr[curr]) == st.end()){
                    for(auto it : mp[arr[curr]]){
                        
                        if(!vis[it]){
                            vis[it] = true;
                            qu.push(it);
                        }
                    }
                    st.insert(arr[curr]);
                }

                int prev = curr-1, nx = curr+1;

                if(prev >= 0 && !vis[prev]){
                    qu.push(prev);
                    vis[prev] = true;
                }
                if(nx < n && !vis[nx]){
                    qu.push(nx);
                    vis[nx] = true;
                }
            }
            cnt++;
        }
        return cnt;
    }
};