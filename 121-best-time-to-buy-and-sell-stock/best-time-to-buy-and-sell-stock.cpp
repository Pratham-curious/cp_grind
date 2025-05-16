class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int n = prices.size();
        int ans = 0;
        for(int i=1;i<n;i++){
            if(prices[i]<mini) mini = prices[i];
            else ans = max(ans,prices[i]-mini);
        }
        return ans;
    }
};