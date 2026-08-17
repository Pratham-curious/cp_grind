class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pref(n+1,0);

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1]+stoneValue[i-1];
        }

        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i+len-1;
                int value = 0;
                for(int k=i;k<j;k++){
                    if(pref[k+1]-pref[i] > pref[j+1]-pref[k+1]){
                        value = max(value,pref[j+1]-pref[k+1] + dp[k+1][j]);
                    }
                    else if(pref[k+1]-pref[i] < pref[j+1]-pref[k+1]){
                        value = max(value,pref[k+1]-pref[i] + dp[i][k]);
                    }
                    else{
                        value = max(value,pref[k+1]-pref[i] + max(dp[i][k],dp[k+1][j]));
                        
                    }
                }
                dp[i][j] = value;
            }
        }
        return dp[0][n-1];
    }
};