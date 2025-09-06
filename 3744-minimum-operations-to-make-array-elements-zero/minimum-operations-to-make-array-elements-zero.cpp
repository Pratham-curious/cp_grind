class Solution {
public:
#define ll long long
    long long minOperations(vector<vector<int>>& queries) {

        ll ans = 0;

        for (auto i : queries) {

            ll start = i[0];
            ll end = i[1];

            ll operations = 0;

            ll prev = 1;

            ll curr = 1;

            for (ll cost = 1; cost < 17; cost++) {
                curr = curr * 4LL;
                ll l = max(start, prev);
                ll r = min(end, curr - 1);

                if (r >= l) {
                    operations += (r - l + 1) * cost;
                }
                prev = curr;
            }

            ans += (operations + 1) / 2;
        }

        return ans;
    }
};