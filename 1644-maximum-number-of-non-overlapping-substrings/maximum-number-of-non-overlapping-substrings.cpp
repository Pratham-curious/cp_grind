class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> f(26,vector<int>(2,-1));
        vector<bool> vis(26,false);

        int n = s.size();
        set<pair<int,int>> st,s1;

        for(int i=0;i<n;i++){
            int c = s[i]-'a';
            if(f[c][0] == -1){
                f[c][0] = f[c][1] = i;
            }
            else{
                f[c][1] = i;
            }
        }

        for(int i=0;i<n;i++){
           int c = s[i]-'a';
           if(!vis[c]){
                vis[c] = true;
                if(st.empty()){
                    st.insert({f[c][1],c});
                  //  cout<<"enter fresh "<<i<<endl;
                }
                else{
                    auto it = st.upper_bound({f[c][1],-1});
                    if(it != st.begin()){
                        if(it == st.end()) it = prev(st.end());
                        else --it;
                        int ch = (*it).second;
                        f[ch][1] = f[c][1];
                        f[c][0] = f[ch][0];
                        st.erase(*it);
                        st.insert({f[c][1],c});
                    }
                    else{
                        st.insert({f[c][1],c});
                    }
                }    
           }
           while(!st.empty() && f[c][1] > (*st.begin()).first){
                int ch = (*st.begin()).second;
             //   cout<<ch<<endl;
                f[ch][1] = max(f[c][1],f[ch][1]);
                f[ch][0] = min(f[ch][0],f[c][0]);
                f[c][0] = f[ch][0];
                f[c][1] = f[ch][1];
                st.erase(st.begin());
           }
           if(i == (*st.begin()).first){
            //cout<<i<<endl;
            int ch = (*st.begin()).second;
            s1.insert({f[ch][1],f[ch][0]});
            st.erase(st.begin());
           }
        }
        vector<string> ans;
        int curr  = -1;
        while(!s1.empty()){
            auto it = *s1.begin();
            s1.erase(it);
            int start = it.second, finish = it.first;
            if(curr < start){
                ans.push_back(s.substr(start,finish-start+1));
                curr = start;
            }

        }
        return ans;
    }
};