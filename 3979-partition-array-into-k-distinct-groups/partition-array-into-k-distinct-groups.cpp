class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0) return false;
        int m = n/k;
        map<int,int> mp;
        for(auto it : nums) mp[it]++;
        for(auto it : mp) if(it.second > m) return false;
        return true;
    }
};