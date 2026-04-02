class Solution {
public:
#define ll long long
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();

        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(m,vector<ll>(3,INT_MIN)));

        if(n == 1 && m == 1){
            return coins[0][0] < 0 ? 0 : coins[0][0];
        }

        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = coins[0][0] < 0 ? 0 : coins[0][0];
        dp[0][0][2] = INT_MIN;

        // cout<<"[ "<<dp[0][0][0]<<", "<<dp[0][0][1]<<", "<<dp[0][0][2]<<" ]"<<"  ";

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 && j == 0) continue;
                if(i - 1 >= 0){
                    dp[i][j][0] = max(coins[i][j] + dp[i-1][j][0],dp[i][j][0]);
                    dp[i][j][1] = max({ (coins[i][j] < 0 ? 0 : coins[i][j]) + dp[i-1][j][0], dp[i][j][1] , coins[i][j] + dp[i-1][j][1] } );
                    dp[i][j][2] = max({(coins[i][j] < 0 ? 0 : coins[i][j] )+ dp[i-1][j][1] , dp[i][j][2] , coins[i][j] + dp[i-1][j][2] });

                }
                if(j -1 >= 0){

                    dp[i][j][0] = max(coins[i][j] + dp[i][j-1][0],dp[i][j][0]);
                    dp[i][j][1] = max({ (coins[i][j] < 0 ? 0 : coins[i][j]) + dp[i][j-1][0], dp[i][j][1] , coins[i][j] + dp[i][j-1][1] } );
                    dp[i][j][2] = max({(coins[i][j] < 0 ? 0 : coins[i][j]) + dp[i][j-1][1] , dp[i][j][2] , coins[i][j] + dp[i][j-1][2] });
                }
                //cout<<"[ "<<dp[i][j][0]<<", "<<dp[i][j][1]<<", "<<dp[i][j][2]<<" ]"<<"  ";
            }
            //cout<<endl;
        }
        return dp[n-1][m-1][2];

    }
};