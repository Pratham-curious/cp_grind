class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int o1 = INT_MAX , e1= INT_MAX;

        for(int i=0;i<n;i++){
            if(nums1[i] & 1) {
                o1 = min(o1,nums1[i]);
            }
            else{ 
                e1 = min(e1,nums1[i]);
            }
        }
        if(e1 > o1  || o1 == INT_MAX) return true; // we can make everything odd
        // to make everything even => there should be no odd 
        return false;
    }
};