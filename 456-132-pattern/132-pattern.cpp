class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        multiset<int> st;
        for(int i=n-1;i>=1;i--){
            st.insert(nums[i]);
        }
        for(int i=1;i<n;i++){
            auto it = st.lower_bound(nums[i]);
            if(it != st.begin()){
                it--;
                if(mini < *it) return true;
            }
            mini = min(mini,nums[i]);
                st.erase(st.find(nums[i]));
        }
        return false;
    }
};