class Solution {
public:
    bool check(string& s, int low, int high) {
        while (low <= high) {
            if (s[low] != s[high])
                return false;
            low++, high--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (check(s, j, i)) {
                    if (j > 0)
                        dp[i] = min(dp[i], 1 + dp[j - 1]);
                    else
                        dp[i] = 0;
                }
            }
        }
        return dp[n-1];
    }
};