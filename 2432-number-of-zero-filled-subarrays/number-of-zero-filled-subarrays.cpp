class Solution {
public:
    #define ll long long
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans = 0,cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == 0) cnt++;
            else cnt = 0;
            ans+=cnt;
        }
        return ans;
    }
};