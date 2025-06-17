#define ll long long

class Solution {
public:
    static const int N = 1e5 + 1;
    static const ll M = 1e9 + 7;

    vector<int> fac;
    vector<int> infac;

    int expo(int a, int b) {
        int res = 1;
        while (b > 0) {
            if (b & 1)
                res = (1LL * res * a) % M;
            a = (1LL * a * a) % M;
            b >>= 1;
        }
        return res;
    }

    int inv(int n) { return expo(n, M - 2); }

    void precom() {
        fac.assign(N + 1, 0);
        infac.assign(N + 1, 0);
        fac[0] = 1;
        for (int i = 1; i <= N; i++) {
            fac[i] = (1LL * fac[i - 1] * i) % M;
        }

        infac[N] = inv(fac[N]);
        for (int i = N - 1; i >= 0; i--) {
            infac[i] = (1LL * infac[i + 1] * (i + 1)) % M;
        }
    }

    int countGoodArrays(int n, int m, int k) {
        precom();
        int deno = (1LL * infac[k] * infac[n - k-1]) % M;
        int num = (1LL * fac[n-1] * m) % M;
        num = (1LL * num * expo(m - 1, n - k - 1)) % M;
        return (1LL * num * deno) % M;
    }
};
