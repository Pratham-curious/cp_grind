class Solution {
public:
    bool cal(vector<int>& temp, vector<bool>& vis, int sum, int cnt) {
        int m = temp.size();
        if (cnt >= m) {
            int val = sum;
            while (val % 2 == 0)
                val /= 2;
            if (val == 1)
                return true;
            return false;
        }
        for (int i = 0; i < m; i++) {
            if (!vis[i]) {
                vis[i] = true;
                if (cal(temp, vis, sum * 10 + temp[i], cnt + 1))
                    return true;
                vis[i] = false;
            }
        }

        return false;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> temp;
        while (n > 0) {
            temp.push_back(n % 10);
            n /= 10;
        }
        int m = temp.size();
        vector<bool> vis(m, false);
        for (int i = 0; i < m; i++) {
            if (temp[i] != 0) {
                vis[i] = true;
                if (cal(temp, vis, temp[i], 1))
                    return true;
                vis[i] = false;
            }
        }
        return false;
    }
};