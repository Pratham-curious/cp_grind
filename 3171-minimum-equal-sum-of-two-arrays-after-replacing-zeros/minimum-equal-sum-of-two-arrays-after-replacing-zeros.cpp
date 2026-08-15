class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n =  nums1.size() , m = nums2.size();
        int x = 0, y= 0;
        long long a1 = 0 , a2 = 0;

        for(int i=0;i<n;i++){
            a1 += nums1[i];
            if(nums1[i] == 0){
                a1++;
                x++;
            }
        }
        for(int i=0;i<m;i++){
            a2 += nums2[i];
            if(nums2[i] == 0){
                a2++;
                y++;
            }
        }
        if(a1 == a2){
            return a1;
        }
        else if(x == 0 && y == 0){
            return -1;
        }
        else if(a2 > a1 && x > 0){
            return a2;
        }
        else if(a1 > a2 && y > 0){
            return a1;
        }
        return -1;
    }
};