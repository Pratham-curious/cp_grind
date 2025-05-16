class Solution {
public:
    int hamming(string a,string b){
        int n = a.size();
        int cnt = 0;
        for(int i=0;i<n;i++) cnt+=(a[i]!=b[i]);
        return cnt;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<pair<int,int>> dp(n);
        for(int i=0;i<n;i++){
            dp[i]={1,i};
            for(int j=i-1;j>=0;j--){
                if(words[i].size() == words[j].size() && groups[i]!=groups[j]){
                    if( hamming(words[i],words[j]) == 1 ){
                        if(dp[j].first + 1 >  dp[i].first){
                            dp[i]={dp[j].first+1,j};
                        }
                    }
                }
            }
        }
        int idx = 0;
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(dp[i].first >= maxi){
                maxi = dp[i].first;
                idx = i;
            }
        }
        vector<string> ans;
        while(dp[idx].second != idx){
            ans.push_back(words[idx]);
            idx = dp[idx].second;
        }
        ans.push_back(words[idx]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};