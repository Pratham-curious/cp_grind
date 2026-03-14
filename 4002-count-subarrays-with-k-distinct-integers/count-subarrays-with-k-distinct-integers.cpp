class Solution {
public:
#define ll long long
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size();
        ll ans = 0, left = 0,count = 0,back = 0,prev = 1;
        map<ll,ll> mp,extra;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            extra[nums[i]]++;
            if(mp[nums[i]] == m) count++;
            while(mp.size() > k){
                prev = 1;
                mp[nums[left]]--;
                extra[nums[left]]--;
                if(mp[nums[left]] == m-1) count--;
                if(mp[nums[left]] == 0){ 
                    mp.erase(nums[left]);
                    extra.erase(nums[left]);
                }
               
                left++;
                back = left;
            }
            if(count == k){
                while(extra[nums[back]] > m){
                    prev++;
                    extra[nums[back]]--;
                    back++;
                }
                ans += prev;
            }
        }
        return ans;
    }
};