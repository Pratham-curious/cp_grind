class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[1] == b[1]) return a[0]<b[0];
        return a[1] < b[1];
    }
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int ans = 0, maxi = 0;
        map<int,vector<int>> start;
        for(int i=0;i<n;i++){
            start[events[i][0]].push_back(events[i][1]);
            maxi = max(maxi,events[i][1]);
        }
        multiset<int> st;
        for(int d =1;d<=maxi;d++){
            if(start.find(d) != start.end()) for(auto it : start[d]) st.insert(it);
            auto it  = st.lower_bound(d);
            if(it == st.end()) continue;
            ans++;
            st.erase(st.find(*it));
        }
        return ans;
    }
};