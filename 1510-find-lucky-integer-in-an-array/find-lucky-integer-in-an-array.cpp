class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(501,0);
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        int val = -1;
        for(int i=1;i<=500;i++){
            if(freq[i] == i) val = i;
        }
        return val;
    }
};