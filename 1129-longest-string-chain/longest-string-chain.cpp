class Solution {
public:
    bool check(string s,string t){
        int n = s.size(), m = t.size();
        if(n+1 != m) return false;
        int cnt = 0;
        for(int i=0,j=0;i<n && j<m;j++){
            if(s[i] == t[j]) i++;
            else cnt++;
        }
        if(cnt >= 2) return false;
        return true;
    }
    static bool comp(const string& a,const string& b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n+1,1);
        sort(words.begin(),words.end(),comp);
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(check(words[j-1],words[i-1])){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        int maxi = 0;
        for(auto it : dp) maxi = max(maxi,it);
        return maxi;
    }
};