class Solution {
public:
/*

observation :

1. i can go only forward, so maximum possible jump is any way n-1
2. if i have 2 , 5,10 and target is 8 so i will jump tp 5 first then 10 ->
    -> that means if i can jump to j from i , i<k<j , such that nums[i] < nums[k]<nums[j] i can jump.
3.can se as dp[i], where dp[i] is maximum jump you can take to reach i, since we can go only forward i will se only the previous indexs
    -> dp[i] = max(1 + dp[k]), k < i and abs(nums[i]-nums[k]) <= target;

*/
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n,-1);
        dp[0] = 0;

        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j] != -1 && abs(nums[j]-nums[i]) <= target ) dp[i] = max(dp[i],1+dp[j]);
            }
        }
        return dp[n-1];
    }
};