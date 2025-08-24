class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnto = 0,prev = 0;
        int n = nums.size();
        int maxi = 0;
        bool cut = false;
        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                cnto++;
                if(cnto + prev >= maxi){
                    if(prev == 0) cut = false;
                    else cut = true;
                }
                maxi = max(maxi,cnto+prev);
            }
            else{
                if(i > 0 && nums[i-1] == 0){
                    prev = 0;
                    cnto = 0;
                }
                else{
                    prev = cnto;
                    cnto = 0;
                }
            }
        }
        if(maxi != n) return maxi;
        return max(0,maxi - 1) ;
    }
};