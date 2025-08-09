class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int mini = -1, ans = 0;
        for(int i=0;i<n;i++){
            if(weight[i]>=mini) mini = weight[i];
            else{
                ans++;
                mini = -1;
            }
        }
        return ans;
    }
};