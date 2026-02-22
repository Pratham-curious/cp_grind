class Solution {
public:
    int binaryGap(int n) {
        int cnt = 0, ans = 0;
        int fnd = 0;
        while (n > 0) {
            if (n & 1) {
                if (!fnd){
                    fnd = 1;
                    cnt = 1;
                }
                else {
                    ans = max(ans, cnt);
                    cnt = 1;
                }
            } else
                cnt++;
            n >>= 1;
        }
        return ans;
    }
};