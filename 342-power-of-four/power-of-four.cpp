class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 0 ) return false;
        return (!(n & (n-1)) && (n%10 == 4 || n%10 == 6 || n == 1));
    }
};