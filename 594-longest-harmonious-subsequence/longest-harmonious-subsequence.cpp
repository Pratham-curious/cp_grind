class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0, j = 0;
        for(int i=0;i<n;i++){
            while(j+1 < n && nums[j+1]-nums[i] <= 1) j++;
            if(nums[j]-nums[i] ==1) ans = max(ans,j-i+1);
        }
        return ans;
    }
};