class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = INT_MAX;
        multiset<int> st;
        if(x == 0){
            return 0;
        }
        for(int i=x-1;i<n;i++){
            st.insert(nums[i]);
        }
        for(int i=0;i<n-x;i++){
            st.erase(st.find(nums[i+x-1]));
            auto it = st.upper_bound(nums[i]);
            if(it != st.end())ans = min(ans,*it-nums[i]);
            if(it != st.begin()) ans = min(ans,nums[i]-*(--it));
        }
        return ans;
    }
};