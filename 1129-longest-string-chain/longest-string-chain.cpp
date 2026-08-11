class Solution {
public:
    void check(string& t,vector<int>& dp,vector<string>& words,int curr){
        int n = words.size();
        for(int i = 0;i<curr;i++){
            if(t == words[i]) dp[i] = max(dp[i],dp[curr]+1);
        }
    }
    static bool comp(const string& a , const string& b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);

        for(int i=n-1;i>=0;i--){
            string s = words[i];
            int m = s.size();
            
            for(int j = 0;j<m;j++){
                string t = s.substr(0,j) + s.substr(j+1);
                check(t,dp,words,i);
            }
            
        }
        int ans = 0;
        for(auto it : dp) ans = max(ans, it);
        return ans;
    }
};