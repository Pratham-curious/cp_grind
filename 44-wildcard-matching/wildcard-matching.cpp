class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // j-> s, i-> p
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        if (m == 0) {
            for (auto it : p)
                if (it != '*')
                    return false;
            return true;
        }
        dp[0][0] = true;
        if (p[0] == '*') {
            if (p[0] == '*') {
                for (int i = 0; i <= m; i++)
                    dp[0][i] = true;
            }
        }
       for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(p[i-1] != '*' && p[i-1] != '?'){
                    if(j>0 && p[i-1] == s[j-1]) dp[i][j] = dp[i-1][j-1];
                }
                else{
                    if(p[i-1]=='*') {
                        dp[i][j] = dp[i-1][j];
                        if(j> 0) dp[i][j] = dp[i][j]|dp[i-1][j-1] | dp[i][j-1];
                    }
                    else{
                        if(j>0) dp[i][j]=dp[i-1][j-1];
                    }
                }
            }
        }
        return dp[n][m];
    }
};