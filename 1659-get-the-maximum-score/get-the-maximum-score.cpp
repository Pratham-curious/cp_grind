class Solution {
public:
    long long const mod =1e9+7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long maxi = 0;
        int n = nums1.size(), m = nums2.size();
        long long val1 = 0, val2 = 0;
        int i =0,j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                val1= val1+nums1[i];
                i++;
            }
            else if(nums1[i]>nums2[j]){
                val2+=nums2[j];
                j++;
            }
            else{
                maxi += nums1[i]+max(val1,val2);
                val1 = 0, val2 = 0;
                i++,j++;
            }
        }
        while(i<n) val1+=nums1[i++];
        while(j<m) val2+=nums2[j++];
        maxi+=max(val1,val2);
        return maxi%mod;
    }
};