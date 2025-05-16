class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=1;
            for(int j=i;j>=1;j--){
                if(nums[i-1]>nums[j-1]) dp[i] = max(dp[i],1+dp[j]);
            }
        }
        int maxi = 0;
        for(auto it : dp) maxi = max(maxi,it);
        return maxi;
    }
};