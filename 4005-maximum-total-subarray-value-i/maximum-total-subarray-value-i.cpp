class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        ans =( (long long)k)*(nums[n-1]-nums[0]);
        return ans;
    }
};