class Solution {
public:
    #define ll long long
    const ll M = 1e9 + 7; 
    const ll N = 1e6;
    vector<ll> fac;

    void comp() {
        fac.resize(N + 1, 1);
        for (ll i = 1; i <= N; i++)
            fac[i] = (fac[i - 1] * i) % M;
    }

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        if (n == 1) return 1;

        int init = complexity[0];
        vector<int> sorted = complexity;
        sort(sorted.begin(), sorted.end());

        if (sorted[0] != init || (n > 1 && sorted[0] == sorted[1]))
            return 0;
        

        comp();
        int ans = 1;
        ans = (ans*(fac[n-1]))%M;

        return ans;
    }
};
