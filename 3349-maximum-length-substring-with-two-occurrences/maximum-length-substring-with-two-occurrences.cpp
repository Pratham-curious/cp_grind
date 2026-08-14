class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int> alp(128,0);

        int left = 0,ans = 0;
        for(int i=0;i<n;i++){
            alp[s[i]]++;
            while(alp[s[i]]>2 && left < i){
                alp[s[left]]--;
                left++;

            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};