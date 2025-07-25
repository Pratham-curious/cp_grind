class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        set<int> st;
        for(auto it : nums) st.insert(it);
        if(*st.rbegin() < 0){
            return *st.rbegin();
        }
        while(!st.empty()){
            int val = *st.begin();
            if(val >= 0) sum+=val;
            st.erase(val);
        }
        return sum;
    }
};