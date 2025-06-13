class Solution {
public:
#define ll long long
    bool isRobotBounded(string instructions) {
        string s = instructions;
        ll x = 0, y = 0;
        ll left = 0, right = 0;
        for (auto it : s) {
            if (it == 'G') {
                ll val = right - left;
                if (val == 0)
                    x++;
                else if (abs(val) == 2)
                    x--;
                else if (val == -3 || val == 1)
                    y++;
                else
                    y--;
            } else if (it == 'L') {
                left++;
                left %= 4;
                ;
            } else {
                right++;
                right %= 4;
            }
        }
        if (abs(right - left) != 0) {
            return true;
        } else {
            if (x == 0 && y == 0) return true;
            else
                return false;
        }
        return false;
    }
};