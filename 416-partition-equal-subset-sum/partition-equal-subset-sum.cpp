class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums) sum+=it;
        if(sum & 1) return false;
        sum /=2;
        vector<int> dp(sum+1,false);
        dp[0]=true;
        for(int i=0;i<n;i++){
            for(int j=sum;j>=nums[i];j--){
                dp[j] |= dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};