class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        vector<int> ans(n,0);
        for(auto it : nums) cnt+=it==0;
        long long res = 1;
        for(auto it : nums) if(it != 0 ) res*=it;
        if(cnt == 1){
            for(int i=0;i<n;i++) if(nums[i]==0) ans[i]=res;
        }
        else if(cnt == 0){
            for(int i=0;i<n;i++) ans[i]=res/nums[i];
        }
        return ans;
    }
};