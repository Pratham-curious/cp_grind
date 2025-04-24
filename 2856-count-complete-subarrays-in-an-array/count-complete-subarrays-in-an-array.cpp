class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        int ans = 0;
        int left = 0;
        map<int,int> mp;
        for(auto it : nums) mp[it]++;
        map<int,int> temp;
        for(int i=0;i<nums.size();i++){
            temp[nums[i]]++;
            while(temp.size()>=mp.size()){
                temp[nums[left]]--;
                if(temp[nums[left]]==0) temp.erase(nums[left]);
                left++;
            }
            if(temp.size()<mp.size()) ans+=(i-left+1);
        }
        return sum-ans;

    }
};