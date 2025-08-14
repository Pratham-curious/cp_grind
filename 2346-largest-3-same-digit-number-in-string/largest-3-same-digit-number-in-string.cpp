class Solution {
public:
    string largestGoodInteger(string nums) {
        vector<bool> vis(10, false);
        int n = nums.size();
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2])
                vis[nums[i] - '0'] = true;
        }
        string ans = "";
        int idx = -1;
        for (int i = 0; i < 10; i++) {
            if (vis[i]) {
                idx = i;
            }
        }
        if (idx != -1) {
            for (int j = 0; j < 3; j++) {
                ans += idx + '0';
            }
        }
        return ans;
    }
};