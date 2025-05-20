class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int  n = queries.size();
        int m = nums.size();
        vector<int> temp(m,0);
        for(int i=0;i<n;i++){
            int x = queries[i][0], y = queries[i][1];
            if(y+1<m) temp[y+1]+=1;
            temp[x]-=1;
        }
        if(nums[0]+temp[0]>0) return false;
        for(int i=1;i<m;i++) {
            temp[i]+=temp[i-1];
            if(nums[i]+temp[i]>0) return false;
        }
        return true;
    }
};