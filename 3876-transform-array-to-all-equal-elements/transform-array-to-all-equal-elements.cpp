class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        vector<int> temp = nums;
        int maxi = INT_MAX;
        for(int i=0;i<n-1;i++){
            if(temp[i] < 0){
                cnt++;
                temp[i] = 1;
                temp[i+1]=-temp[i+1];
            }
        }
        if(temp[n-1] == 1) maxi=min(maxi,cnt);
        temp = nums;
        cnt = 0;
         for(int i=0;i<n-1;i++){
            if(temp[i] > 0){
                cnt++;
                temp[i] = -1;
                temp[i+1]=-temp[i+1];
            }
        }
        if(temp[n-1] == -1) maxi=min(maxi,cnt);
        if(maxi > k ) return false;
        return true;

    }
};