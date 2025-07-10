class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int sum = 0;
        for(int i=1;i<n;i++){
            sum += max(0,prices[i]-prices[i-1]);
        }
        return sum;
    }
};