class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0;
        int cnt = 0;
        int n = nums.size();
        int left = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==0) cnt++;
            while(cnt>k){
                if(nums[left]==0) cnt--;
                left++;
            }
            if(cnt<=k) maxi = max(maxi,i-left+1);
        }
        return maxi;
    }
};