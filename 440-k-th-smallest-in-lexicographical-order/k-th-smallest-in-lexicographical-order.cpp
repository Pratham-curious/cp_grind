class Solution {
public:
    int count(int n,long a, long b){
        int steps = 0;
        while(a<=n){
            steps+= min((long)(n+1),b)-a;
            a*=10;
            b*=10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while(k > 0){
            int step = count(n,curr,curr+1);
            if(step<=k){
                curr++;
                k-=step;
            }
            else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};