class Solution {
public:
    long long appealSum(string s) {
        vector<int> freq(26,-1);
        long long n = s.size();
        long long ans = 0;
        for(long long i=0;i<n;i++){
            ans += (i-freq[s[i]-'a'])*(n-i);
            freq[s[i]-'a'] = i;
        }
        return ans;

    }
};