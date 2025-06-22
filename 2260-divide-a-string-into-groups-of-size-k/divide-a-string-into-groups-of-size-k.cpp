class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        for(int i=0;i<(k-(n%k))%k;i++) s+=fill;

        vector<string> ans;
        for(int i=0;i<n;i+=k){
            ans.push_back(s.substr(i,k));
        }
        return ans;
        
    }
};