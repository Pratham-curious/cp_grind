class Solution {
public:
#define ll long long
    bool check(ll n, int k) {
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n % k);
            n /= k;
        }

        int i = 0, j = digits.size() - 1;
        while (i < j) {
            if (digits[i++] != digits[j--])
                return false;
        }
        return true;
    }
    void cal(ll curr, ll r, ll l, int& n, ll& sum, int k) {
        if (n <= 0)
            return;

        if (r < l) {
            if (check(curr, k)) {
                sum += curr;
                n--;
            }
            return;
        }

        for (ll i = 0; i <= 9; i++) {
            if (curr == 0 && r >= l && i == 0)
                continue;

            ll next = 0;
            if (r != l)
                next = curr + r * i + l * i;
            else
                next = curr + r * i;

            cal(next, r / 10, l * 10, n, sum, k);
        }
    }

    long long kMirror(int k, int n) {
        ll sum = 0;

        for (int d = 1; d <= 17 && n > 0; d++) {
            ll r = 1;
            for (int i = 1; i < d; i++)
                r *= 10;
            ll l = 1;
            cal(0LL, r, l, n, sum, k);
        }

        return sum;
    }
};
