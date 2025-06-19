class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 1;
        sort(nums.begin(),nums.end());
        int curr =  nums[0]+k;
        for(int i=0;i<n;i++){
            if(nums[i]>curr){
                cnt++;
                curr = nums[i]+k;
            }
        }
        return cnt;
    }
};