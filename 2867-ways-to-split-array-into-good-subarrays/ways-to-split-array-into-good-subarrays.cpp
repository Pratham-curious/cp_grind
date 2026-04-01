class Solution {
public:
#define ll long long
ll mod = 1e9+7;

    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;

        int i = 0,j = n-1;

        while(i < n && nums[i] != 1) i++;
        while(j >= 0 && nums[j] != 1) j--;
        if(i == j) return 1;
        if( i > j) return 0;

        ans = 1;
        ll cnt = 1;
        for(int k=i+1;k<=j;k++){
            if(nums[k] == 1){
               ans = (ans* cnt)%mod; 
               cnt = 0;
            }
            cnt = (cnt + 1)%mod;
        }
        return ans;
    }
};