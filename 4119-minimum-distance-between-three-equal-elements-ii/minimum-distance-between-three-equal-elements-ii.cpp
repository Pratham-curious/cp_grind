class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> mp;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) == mp.end() || mp[nums[i]].size() == 1){
                mp[nums[i]].push_back(i);
            }
            else{
                int m = mp[nums[i]].size();
                int val = mp[nums[i]][m-2];
                ans = min(ans,2*(i-val));
                mp[nums[i]].push_back(i);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};