class Solution {
public:
    int bitwiseComplement(int n) {
        int m = 0,temp = n;
        if(n == 0) return 1;
        while(temp > 0){
            m++;
            temp>>=1;
        }
        return (((1 << m )-1) ^ n);
    }
};