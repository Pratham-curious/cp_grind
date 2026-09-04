class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n,0), mini(n,0);

        maxi[0] = nums[0] , mini[n-1] = nums[n-1];

        for(int i=1;i<n;i++) maxi[i] = max(maxi[i-1],nums[i]);
        for(int i=n-2;i>=0;i--) mini[i] = min(mini[i+1],nums[i]);


        int index = n,val = INT_MAX;

        for(int i=0;i<n;i++) {
            int v1 = maxi[i]-mini[i];
            if(v1 > k) continue; 

            index = min(index,i);
        }

        return index == n ? -1 : index;
    }
};