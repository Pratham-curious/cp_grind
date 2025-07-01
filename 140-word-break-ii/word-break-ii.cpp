class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<string>> dp(n+1);
        set<string> st;
        for(auto it : wordDict) st.insert(it);

        for(int i=1;i<=n;i++){
            string temp = "";
            for(int j=i;j>=1 && i-j+1<=10 ;j--){
                temp = s[j-1]+temp;
                if(st.find(temp) != st.end()){
                    int m = dp[j-1].size();
                    if(j-1 == 0){
                        dp[i].push_back(temp);
                    }
                    else if( m != 0){
                        for(int k=0;k<m;k++){
                            dp[i].push_back(dp[j-1][k]+" "+temp);
                        }
                    }
                }
            }
        }
        return dp[n];
    }
};