class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        // 1000 ->1, 100,000 -> 2

        ans = max(0,n - 999);
        return ans;
    }
};