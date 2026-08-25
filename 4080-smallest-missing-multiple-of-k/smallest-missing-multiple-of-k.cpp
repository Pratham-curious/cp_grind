class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> f(101,0);

        for(auto it : nums){
            if(it%k == 0) f[it/k] = 1;
        }

        for(int i=1;i<=100;i++) if(f[i] == 0) return k*i;
        return k*101;

    }
};