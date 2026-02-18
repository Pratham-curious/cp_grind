class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long v = (long)n + (n>>1) + (long long )1;
        return !(v & (v-1));
    }
};