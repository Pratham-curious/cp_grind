class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size(),ans = 3;
        vector<int> pref(n,0), suff(n,0);
        pref[1] = 1, suff[n-2] = 1;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]) pref[i] = 1 + pref[i-1];
            else pref[i] = 1;
            ans = max({ans,pref[i]+1,pref[i-1]+2});
        }
        for(int i=n-3;i>=0;i--){
            if(nums[i+1]-nums[i] == nums[i+2]-nums[i+1]) suff[i] = 1 + suff[i+1];
            else suff[i] = 1;
            ans = max({ans,suff[i]+1,suff[i+1]+2});
        }
        if(pref[n-1] == n-1) return n;
        for(int i=1;i<n-1;i++){
           int val = (nums[i-1]+nums[i+1]);
           if(val %2 == 1) continue;
           val/=2;
           int left = 0,right = 0;
           if(i+2 < n) {
            if(nums[i+2]-nums[i+1] == nums[i+1]- val) right = 1 + suff[i+1] + 2;
           }
           if(i-2 >= 0){
           // cout<<"for i ; " <<i<<endl;
            if(nums[i-1]-nums[i-2] == val-nums[i-1]) left = 1 + pref[i-1] + 2;
           }
           if(right > 0 && left > 0 )ans = max(ans,left+right - 3 );
           else ans = max({ans,left,right});
        }
        return ans;
    }
};