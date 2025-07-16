class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0, odd = 0, alt = 0;
        int rev = (nums[0] & 1);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                odd++;
                if(rev == 1){
                    alt++;
                    rev = 0;
                }
            }
            else{
                even++;
                if(rev == 0){
                    rev =1;
                    alt++;
                }
            }
        }
        return max({odd,even,alt});
    }
};