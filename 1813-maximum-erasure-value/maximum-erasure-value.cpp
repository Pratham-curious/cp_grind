class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int curr = 0, maxi = 0;
        int left = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            curr+=nums[i];
            while(mp[nums[i]] > 1){
                mp[nums[left]]--;
                curr-=nums[left];
                left++;
            }
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};