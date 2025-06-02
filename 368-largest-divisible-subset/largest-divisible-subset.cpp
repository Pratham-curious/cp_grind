class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> par(n+1,-1);
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(nums[i-1]%nums[j-1] == 0){
                    if(dp[i] < 1+dp[j]){
                        dp[i] = 1+dp[j];
                        par[i-1]=j-1;
                    }
                }
            }
        }
        vector<int> ans;
        int idx = 0;
        int maxi = 0;
        for(int i=1;i<=n;i++){
            if(maxi < dp[i]){
                maxi = dp[i];
                idx = i-1;
            }
        }
        if(maxi == 0){
            return {nums[0]};
        }
        for(int i = idx;i>=0;i = par[i]){
            ans.push_back(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};