class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size(), ans = INT_MIN;
        for(int i=n-1;i>=0;i--){
            ans = max(ans,energy[i]);
            if(i-k>=0) energy[i-k]+=energy[i];
        }
        return ans;
    }
};