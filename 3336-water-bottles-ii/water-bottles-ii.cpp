class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        if(numBottles < numExchange){
            return numBottles;
        }
        int ans = numBottles;
        int emptyBottle = numBottles;
        while(emptyBottle >= numExchange){
            ans++;
            emptyBottle = emptyBottle-numExchange+1;
            numExchange++;
        }
        return ans;
    }
};