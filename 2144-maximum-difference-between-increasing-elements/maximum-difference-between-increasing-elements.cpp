class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        set<int> st;
        int maxi = -1;
        int n = nums.size();
        st.insert(nums[0]);
        for (int i = 1; i < n; i++) {
            maxi = max(maxi,nums[i]-*st.begin());
            st.insert(nums[i]);
        }
        return maxi==0?-1:maxi;
    }
};