#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        // Find maximum value in nums to size our sieve.
        int maxVal = 0;
        for (int v : nums) maxVal = max(maxVal, v);

        // Linear sieve to compute smallest prime factors up to maxVal.
        vector<int> spf(maxVal + 1);
        vector<int> primes;
        spf[1] = 1;
        for (int i = 2; i <= maxVal; ++i) {
            if (spf[i] == 0) {
                spf[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) {
                long long val = 1LL * p * i;
                if (val > maxVal) break;
                spf[val] = p;
                // If p divides i, we stop to ensure each composite is marked by its smallest prime factor.
                if (p == spf[i]) break;
            }
        }

        // Mark prime numbers quickly.
        vector<bool> isPrime(maxVal + 1, false);
        for (int i = 2; i <= maxVal; ++i) {
            if (spf[i] == i) isPrime[i] = true;
        }

        // Build a map from prime p to indices j with nums[j] divisible by p.
        // We use an unordered_map because only primes dividing nums[j] appear as keys.
        unordered_map<int, vector<int>> bucket;
        bucket.reserve(n * 2);
        for (int j = 0; j < n; ++j) {
            int x = nums[j];
            // Factorize x into distinct prime factors using spf.
            while (x > 1) {
                int p = spf[x];
                bucket[p].push_back(j);
                while (x % p == 0) x /= p;
            }
        }

        // BFS to find minimum jumps.
        vector<int> dist(n, -1);
        deque<int> dq;
        dist[0] = 0;
        dq.push_back(0);
        // Track which primes’ buckets have been processed to avoid redundant teleports.
        vector<bool> usedPrime(maxVal + 1, false);

        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();
            int d = dist[u];
            if (u == n - 1) return d; // reached end

            // Move to adjacent indices if possible.
            if (u - 1 >= 0 && dist[u - 1] == -1) {
                dist[u - 1] = d + 1;
                dq.push_back(u - 1);
            }
            if (u + 1 < n && dist[u + 1] == -1) {
                dist[u + 1] = d + 1;
                dq.push_back(u + 1);
            }

            // Prime teleportation: if nums[u] is prime and this prime hasn’t been used yet.
            int val = nums[u];
            if (val >= 2 && isPrime[val] && !usedPrime[val]) {
                usedPrime[val] = true;
                auto it = bucket.find(val);
                if (it != bucket.end()) {
                    const vector<int>& indices = it->second;
                    for (int idx : indices) {
                        if (idx != u && dist[idx] == -1) {
                            dist[idx] = d + 1;
                            dq.push_back(idx);
                        }
                    }
                    // No need to clear the vector explicitly; marking usedPrime prevents revisiting.
                }
            }
        }
        return -1; // If no path (should not happen for valid inputs).
    }
};
