class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.rbegin(),temp.rend());
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++) {
            mp[temp[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) != mp.end() && mp[nums[i]]>0){
                ans.push_back(nums[i]);
                mp[nums[i]]--;
            }
        }

        return ans;
    }
};