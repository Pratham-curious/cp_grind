class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int hill = -1, last = -1;
        
        for(int i=1;i<n-1;i++){
            if(last == nums[i]){
                if(nums[i] == nums[i+1]) continue;
                if(hill == 0 && last < nums[i+1]) {cnt++;}
                if(hill == 1 && last > nums[i+1]) {cnt++;}
                

            }
            else if(nums[i] == nums[i+1]){
                last = nums[i];
                if(last > nums[i-1]) hill = 1;
                else if(last < nums[i-1]) hill = 0;
                else last = -1;
            }
            else{
                if(nums[i-1] > nums[i] && nums[i] < nums[i+1]){
                    last = -1;
                    cnt++;
                }
                else if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                    last = -1;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};