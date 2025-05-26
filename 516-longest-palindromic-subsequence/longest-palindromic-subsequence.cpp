class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++) dp[i][i]=1;
        for(int len=2;len<=n;len++){
            for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;
                if(s[i-1]==s[j-1]) dp[i][j] = 2+((i+1<j) ? dp[i+1][j-1] : 0);
                else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[1][n];
    }
};