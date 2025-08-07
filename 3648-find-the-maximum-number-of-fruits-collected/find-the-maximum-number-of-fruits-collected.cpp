class Solution {
public:
    int cal(int row,int col,vector<vector<int>>& fruits,vector<vector<int>>& dp,int drow){
        int n = fruits.size();
        if(row >= n || col >= n || row < 0 || col <0) return INT_MIN;
        if(dp[row][col] != -1) return dp[row][col];
        if(row == n-1 && col == n-1) return 0;
        int ans = INT_MIN;
        if(drow == 1){
            for(int i=-1;i <= 1;i++){
                int nrow = row+1, ncol = col+i;
               // if(nrow<n && nrow >= 0 && ncol>=0 && ncol<n){
                    ans = max(ans,cal(nrow,ncol,fruits,dp,drow));
                  
               // }
            }
        }
        else{
            for(int i=-1;i<=1;i++){
                int nrow = row+i, ncol = col+1;
                //if(nrow<n && nrow >= 0 && ncol>=0 && ncol<n){
                    ans = max(ans,cal(nrow,ncol,fruits,dp,drow));
                  
                //}
            }
        }
        return dp[row][col] = fruits[row][col]+ans;

    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }
        vector<vector<int>> dp1(n,vector<int>(n,-1)),dp2(n,vector<int>(n,-1));
        ans += cal(n-1,0,fruits,dp1,0) + cal(0,n-1,fruits,dp2,1);
        return ans;
    }
};