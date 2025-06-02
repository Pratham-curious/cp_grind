class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n,1), right(n,1);
        for(int i=1;i<n;i++){
                if(arr[i-1]<arr[i]) left[i] = 1+left[i-1];
        }
        for(int i=n-2;i>=0;i--){
                if(arr[i+1]<arr[i]) right[i] =1+right[i+1];
        }
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(left[i] >1 && right[i]>1) maxi = max(maxi,left[i]+right[i]-1);
        }
        return maxi;
    }
};