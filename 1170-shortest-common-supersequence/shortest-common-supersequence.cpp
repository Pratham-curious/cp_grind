class Solution {
public:
    #define ll long long
    string shortestCommonSupersequence(string str1, string str2) {
        ll n = str1.size(), m = str2.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, INT_MAX));
    if(n == 0) return str2;
    if(m == 0) return str1;

    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j - 1], 1 + dp[i - 1][j]);
        }
    }
    string ans;
    int i = n, j = m;
    while (i > 0 && j > 0 )
    {
        if (str2[j - 1] == str1[i - 1])
        {
            ans += str1[i - 1];
            if (dp[i - 1][j - 1] < dp[i][j - 1])
                i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] < 1 + dp[i - 1][j])
            {
                
                ans+=str2[j-1];
                j--;
            }
            else
            {
                ans+=str1[i - 1];
                i--;
            }
        }
    }
    while(i> 0) {ans+=str1[i-1];i--;}
    while(j> 0) {ans+=str2[j-1];j--;}
    reverse(ans.begin(),ans.end());
    
    return ans;

    }
};