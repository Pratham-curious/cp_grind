class Solution {
public:
    int longestSubsequence(string s, int k) {

        int n = s.size();
        vector<int> pref(n, 0);
        if (s[0] == '0')
            pref[0] = 1;
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + (s[i] == '0');

        long long ans = pref[n - 1];
        long long curr = 0;
        for (long long i = n - 1, j = 0; i >= 0 && j < 60; i--, j++) {
            if (s[i] == '1')
                curr += (1LL << j);
            if (curr > k)
                break;
            ans = max(ans, (i > 0 ? pref[i - 1] : 0) + n-i);
        }

        return ans;
    }
};