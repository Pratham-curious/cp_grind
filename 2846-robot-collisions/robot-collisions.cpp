class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        unordered_map<int,int> mp;
        vector<pair<int,pair<int,char>>> v;
        for(int i=0;i<n;i++){
            v.push_back({positions[i],{healths[i],directions[i]}});
            mp[positions[i]] = i;
        }
        sort(v.begin(),v.end());

        vector<int> pos;

        stack<int> st;

        for(int k = 0;k<n;k++){
            if(st.empty()){
                if(v[k].second.second == 'L') pos.push_back(k);
                else st.push(k);
            }
            else{
                if(v[k].second.second == 'L'){
                    while(!st.empty() && v[st.top()].second.first < v[k].second.first){
                        st.pop();
                        v[k].second.first--;
                    }
                    if(st.empty()){
                        if(v[k].second.first > 0) pos.push_back(k);
                    }
                    else if(v[k].second.first == v[st.top()].second.first){
                        st.pop();
                    }
                    else{
                        if(v[st.top()].second.first == 1 ) st.pop();
                        else v[st.top()].second.first--;
                    }
                }
                else{
                    st.push(k);
                }
            }
        }
        while(!st.empty()){
            int idx = st.top();
            st.pop();
            pos.push_back(idx);
        }

        vector<pair<int,int>> temp;

        for(auto it : pos){
            temp.push_back({mp[v[it].first],v[it].second.first});
        }

        sort(temp.begin(),temp.end());
        vector<int> ans;
        for(auto it : temp){
            ans.push_back(it.second);
        }

        return ans;

        
    }
};