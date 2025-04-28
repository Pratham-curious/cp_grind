class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long left = 0, n = nums.size();
        long long sum = 0,len = 0;
        long long ans = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            len++;
            while(sum*len >= k){
                sum-=nums[left];
                len--;
                left++;
            }
            if(sum*len<k) ans+=(i-left+1);
        }
        return ans;
    }
};