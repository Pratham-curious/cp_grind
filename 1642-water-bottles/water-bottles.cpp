class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int n = numBottles,extra = 0;
        while( n >= numExchange){
            ans += (n)/numExchange;
            n = n/numExchange + n%numExchange;
        }
        return ans;
    }
};