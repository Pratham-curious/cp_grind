class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        vector<vector<int>> idx(128,vector<int>());
        for(int i=m-1;i>=0;i--) idx[t[i]].push_back(i);

        vector<unsigned long long> dp(m,0ll);

        for(int i=0;i<n;i++){
            char c = s[i];
            for(auto it : idx[c]){
                if(it == 0) dp[0]++;
                else dp[it] += dp[it-1];
            }
        }

        return dp[m-1];
    }
};