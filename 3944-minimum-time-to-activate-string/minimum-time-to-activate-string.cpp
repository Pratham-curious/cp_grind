class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        long long sum = 0;
        int n = order.size();
        set<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                sum+= (order[i]+1LL) *(n-order[i]);
                st.insert(order[i]);
                if(sum >= k) return 0;
                continue;
            }
            auto it = st.lower_bound(order[i]);
            int x1 = 0, x2 = 0;
            if(it == st.end()) x2 = n-order[i];
            else x2 = *it-order[i];
            if(it == st.begin()) x1 = order[i]+1;
            else x1 = order[i]-*prev(it);
            sum += x1*x2;
            if(sum >= k) return i;
            st.insert(order[i]);
        }
        return -1;
    }
};