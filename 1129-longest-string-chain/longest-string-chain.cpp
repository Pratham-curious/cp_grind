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
    static bool comp(const string& a, const string& b){
    return a.size() < b.size();
}
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        map<string,int> dp;
        sort(words.begin(),words.end(),comp);
        for(int i=0;i<n;i++){
            for(int j = 0;j<words[i].size();j++){
                string a ="",b="";
                a = words[i].substr(0,j);
                if(j != words[i].size()-1) b= words[i].substr(j+1); 
                dp[words[i]] = max(dp[words[i]],1+dp[a+b]);
            }
        }
        int maxi = 0;
        for(auto it : dp) maxi = max(maxi,it.second);
        return maxi;
    }
};