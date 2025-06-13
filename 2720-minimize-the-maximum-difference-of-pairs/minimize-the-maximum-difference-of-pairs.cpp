class Solution {
public:
    bool check(int mid,vector<int>& v, int& p){
        int n = v.size();
        bool pick = false;
        int cnt = 0;
        for(int i=1;i<n;i++){
            if(pick){
                pick = false;
                continue;
            }
            if(v[i]-v[i-1] <= mid){
                cnt++;
                pick = true;
            }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        vector<int> temp = nums;
        int n = nums.size();
        sort(temp.begin(),temp.end());
        int low = 0, high = 1e9;
        while(low <=  high){
            int mid = low + (high-low)/2;
            if(check(mid,temp,p)){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};