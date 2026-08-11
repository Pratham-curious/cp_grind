class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        vector<int> v(52,0);
        for(auto it : nums ) v[it]++;

        for(int i=1;i<n;i++){
            if(nums[i] != nums[i-1] + 1) break;
            sum += nums[i];  
        }
        if(sum > 50) return sum;
        for(int i=sum;i<=51;i++){
            if(v[i]== 0 ) return i;
        }
        return 0;
    }
};