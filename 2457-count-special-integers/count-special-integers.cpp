class Solution {
public:
    int countSpecialNumbers(int n) {
        vector<int> v;
        while (n > 0) {
            v.push_back(n % 10);
            n /= 10;
        }
        vector<bool> vis(10, false);
        int ans = 0;
        int m = v.size();
        for (int i = m-1;i>=0;i--) {
            int cnt = 0;
            for (int j = 0; j < v[i]; j++)
                cnt += (vis[j] == false);
            if(i == m-1) cnt--;
            if(i == 0 && !vis[v[i]]) cnt++;
            int val = cnt;
            int size = i;
            int curr = 10-(m-i);
            while (size--) {
                val *= curr;
                curr--;
            }
            ans += val;
            if (vis[v[i]]) {
                break;
            }
            vis[v[i]] = true;
        }
        for(int i=0;i<m-1;i++){
            int val = 9;
            int curr = 9;
            for(int j=i-1;j>=0;j--){
                val*=curr;
                curr--;
            }
            ans+=val;
        }
        return ans;
    }
};