class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int low = 0 , high = 0;

        for(int i=0;i<n;i++){
            if(nums[i] > nums[high]){
                high = i;
            }
            if(nums[i] < nums[low]){
                low = i;
            }
        }
        if(high < low) swap(high,low);
        return min({low+1 + n-high, high+1,n-low});

    }
};