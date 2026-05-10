class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int lastidx = 0;
        for(int i=0;i<n;i++){
            if(lastidx < i) return false;
            lastidx = max(lastidx,i+nums[i]);
        }

        return true;
    }
};