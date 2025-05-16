class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool found = false;
        int idx = -1;
        for (int i = n - 2; i >= 0; i--) {
            if(nums[i]<nums[i+1]){
                found = true;
                for(int j=i;j<n;j++){
                    if(nums[j]>nums[i]) idx=j;
                }
                swap(nums[idx],nums[i]);
                reverse(nums.begin()+i+1, nums.end());
                break;
            }
        }
        if (!found) {
            sort(nums.begin(), nums.end());
        }
    }
};