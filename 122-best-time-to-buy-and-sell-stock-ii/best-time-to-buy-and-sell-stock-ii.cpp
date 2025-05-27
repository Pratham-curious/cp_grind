class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans = 0;
        int buy = prices[0], sell = prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>=sell) sell=prices[i];
            else{
                ans += sell-buy;
                buy = prices[i];
                sell = prices[i];
            }
        }
        ans+=sell-buy;
        return ans;
    }
};