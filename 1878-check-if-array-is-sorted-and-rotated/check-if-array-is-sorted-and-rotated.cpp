class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = n-1;
        while(i+1 < n && nums[i+1] >= nums[i]) i++;
        while(j-1 >=0 && nums[j-1] <= nums[j]) j--;

        if(i == n-1 || (j-i == 1 && nums[0] >= nums[n-1])) return true;
        return false;
    }
};