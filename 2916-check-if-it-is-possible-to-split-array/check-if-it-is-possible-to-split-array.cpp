class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        vector<int> pref(n+1,0);


        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1]+nums[i-1];
        }
        

        for(int i=0;i<n-1;i++) {
            dp[i][i+1] = true;
            dp[i][i] = true;
        }
        dp[n-1][n-1] = true;
        

        for(int len = 3;len<=n;len++){
            for(int i = 0;i <= n-len ;i++){
                int j = i+len-1;

                bool val = false;

                for(int k=i;k<j;k++){
                    if(k == i){
                        if(pref[j+1] - pref[k+1] >= m) val |= dp[k+1][j];
                    }
                    else if( k == j-1){
                        if(pref[j] - pref[i] >= m ) val |= dp[i][k];
                    }
                    else{
                        if(pref[k+1] - pref[i] >= m && pref[j+1] - pref[k+1] >= m){
                            val |= (dp[i][k] && dp[k+1][j]);
                        }
                    }
                }

                dp[i][j] = val;
            }
        }

        return dp[0][n-1];
    }
};