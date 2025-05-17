class Solution {
public:
    void sortColors(vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
        while (idx < n) {
            if (nums[idx]!=0) break;
            idx++;
        }
        for(int i=idx;i<n;i++){
            if(nums[i]==0){
                swap(nums[i],nums[idx]);
                idx++;
            }
        }
        for(int i=idx;i<n;i++){
            if(nums[i]==1){
                swap(nums[i],nums[idx]);
                idx++;
            }
        }

    }
};