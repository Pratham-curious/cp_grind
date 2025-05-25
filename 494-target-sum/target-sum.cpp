class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       
        int sum = 0;
        target = abs(target);
        for(auto it : nums) sum+=it;
        if((target + sum) & 1) return 0;
        int rem = (target + sum)/2;
         vector<int> dp(rem+1,0);
        int n = nums.size();
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=rem;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[rem];

    }
};