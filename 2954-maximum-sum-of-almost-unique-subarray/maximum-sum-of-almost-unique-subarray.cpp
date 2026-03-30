class Solution {
public:
#define ll long long
    long long maxSum(vector<int>& nums, int m, int k) {
        ll ans = 0,sum = 0;
        int n = nums.size();;
        unordered_map<int,int> mp;

        for(int i=0;i<k;i++){
            sum+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size() >= m) ans = max(ans,sum);
        for(int i=k;i<n;i++){
            sum += nums[i];
            mp[nums[i]]++;

            sum-=nums[i-k];
            mp[nums[i-k]]--;
            if(mp[nums[i-k]] == 0){
                mp.erase(nums[i-k]);
            }
            if(mp.size()>=m){
                ans = max(ans,sum);
            }
        }
        return ans;

    }
};