class Solution {
public:
    void palindrome(string& s, vector<vector<bool>>& dp,int& n){
        for(int i=0;i<n;i++) dp[i][i] = true;
        for(int i=0;i<n-1;i++) if(s[i] == s[i+1]) dp[i][i+1] = true;

        for(int len=3;len<=n;len++){
            for(int i=0;i<= n-len ;i++){
                int j = i+len-1;
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
            }
        }
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        palindrome(s,dp,n);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            int j = i-k+1;
            if(i-1 >= 0) ans[i] = ans[i-1];
            for(int j=i-k+1;j>=0;j--){
                if(dp[j][i]) ans[i] = max(ans[i],1+ (j>=1 ? ans[j-1] : 0));
            }
           // cout<<ans[i]<<" ";
        }
        return ans[n-1];


    }
};