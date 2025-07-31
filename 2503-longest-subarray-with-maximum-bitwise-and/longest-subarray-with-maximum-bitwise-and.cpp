class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), len = 0;
        int high = 0;
        for(auto it : nums) high = max(it,high);
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == high) len++;
            else len=0;
            maxi = max(maxi,len);
        }
        return maxi;
    }
};