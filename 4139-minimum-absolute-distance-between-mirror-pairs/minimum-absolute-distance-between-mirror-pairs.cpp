class Solution {
public:
    int rev(int n){
        int m = 0;
        while(n > 0){
            m = m*10 + n%10;
            n/=10;
        }
        return m;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int ans = n;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) != mp.end()){
                ans = min(ans,i-mp[nums[i]]);
            }
            mp[rev(nums[i])] = i;
        }
        return ans == n ? -1 : ans;
    }
};