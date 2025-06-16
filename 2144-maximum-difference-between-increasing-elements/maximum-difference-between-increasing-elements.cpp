class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        set<int> st;
        int maxi = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if(!st.empty()){
                maxi = max(maxi,nums[i]-*st.begin());
            }
            st.insert(nums[i]);
        }
        return maxi==0?-1:maxi;
    }
};