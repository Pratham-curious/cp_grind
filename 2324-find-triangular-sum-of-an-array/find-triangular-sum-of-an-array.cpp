class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int j=n-1;j>0;j--){
            for(int i=0;i<j;i++){
                nums[i] =( nums[i]+nums[i+1])%10;
            }
        }
        return nums[0];
    }
};;