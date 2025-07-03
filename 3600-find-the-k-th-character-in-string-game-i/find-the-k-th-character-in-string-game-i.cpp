class Solution {
public:
    char kthCharacter(int k) {
        int j = 0;
        while (k > 1) {
            int side = 0;
            while ((1 << side) < k) {
                side++;
            }
            k -= (1 << (side - 1));
            j++;
        }
        char s = 'a' + j;
        return s;
    }
};
