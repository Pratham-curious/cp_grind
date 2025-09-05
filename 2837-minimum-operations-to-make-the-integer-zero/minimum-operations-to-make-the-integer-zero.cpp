class Solution {
public:
    bool check(int n1,int n2,long long mid){
        long long val = n1-mid*n2;
        long long temp = val;
        int cnt = 0;
        while(val > 0){
            cnt += (val & 1LL);
            val>>=1;
        }
        return mid >= cnt && temp >= mid ;
    }
    int makeTheIntegerZero(int num1, int num2) {
        for(long long i=0;i<=60;i++){
            if(num1 <= i*num2) return -1;
            if(check(num1,num2,i)) return i;
        }
        return -1;
    }
};