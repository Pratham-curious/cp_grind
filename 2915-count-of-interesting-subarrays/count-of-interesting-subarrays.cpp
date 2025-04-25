class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>=k && (nums[i]-k)%modulo == 0){
                v[i]++;
            }
        }
        for(int i=1;i<n;i++) v[i]+=v[i-1];
        map<int,int> mp;
        mp[0]=1;
        long long ans = 0;
        for(int i=0;i<n;i++){
            if(v[i]>=k){
                ans+=mp[(v[i]-k)%modulo];
            }
            mp[v[i]%modulo]++;
        }
        return ans;
    }
};