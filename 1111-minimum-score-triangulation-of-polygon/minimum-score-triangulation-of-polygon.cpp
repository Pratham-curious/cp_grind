class Solution {
public:
    int cal(vector<int>& v,vector<vector<int>>& dp, int i,int j){
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX, n = v.size();
        int k = (i+1)%n;
        while(k!=j){
            ans = min(ans,v[i]*v[j]*v[k]+cal(v,dp,i,k)+cal(v,dp,k,j));
            k = (k+1)%n;
        }
        return dp[i][j] = ans == INT_MAX ? 0 : ans;

    }
    int minScoreTriangulation(vector<int>& values) {

        int sum = 0, n = values.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int ans = INT_MAX;
        return cal(values,dp,1,0);
    }
};