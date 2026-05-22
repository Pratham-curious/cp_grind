class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1,ans = 0;
        while(left <= right){
            int m = left + (right-left)/2;
            if(nums[m] <= nums[right]){
                if(nums[m] <= target && target <= nums[right]){
                    ans = m;
                    left = m+1;
                }
                else{
                    right = m-1;
                }
            }
            else{
                if(nums[left] <= target && target <= nums[m]){
                    ans = m;
                    right = m-1;
                }
                else{
                    left = m+1;
                }
            }
           // cout<<left<<" "<<right<<endl;
        }
        return nums[ans] == target ? ans : -1 ;
    }
};