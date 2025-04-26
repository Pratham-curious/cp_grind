class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int lastMinK = -1, lastMaxK = -1, lastBad = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                lastBad = i;
            }
            if (nums[i] == minK) {
                lastMinK = i;
            }
            if (nums[i] == maxK) {
                lastMaxK = i;
            }
            ans += max(0, min(lastMinK, lastMaxK) - lastBad);
        }
        return ans;
    }
};
