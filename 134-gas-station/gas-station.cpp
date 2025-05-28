class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        if (n == 1){
            if(gas[0]<cost[0]) return -1;
            return 0;
        }
        
        int start = 0, end = 1;
        int val = gas[0] - cost[0];
        while (abs(start - end) != 0) {
            if( val >=0){
                val += gas[end]-cost[end];
                end = (end+1)%n;
            }
            else{
                start = (start-1+n)%n;
                val += gas[start]-cost[start];
            }
        }
        if(val < 0) return -1;
        return start;
    }
};