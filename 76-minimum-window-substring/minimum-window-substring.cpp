class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> f(128,0),temp(128,0);

        int n = s.size(), m = t.size();
        for(auto it : t) {
            f[it]++;
        }

        int tot = m;
        int l = 0,r = n,ans = n+1;
        int left = 0;

        for(int i=0;i<n;i++){
            if(f[s[i]] > 0){
                if(temp[s[i]] < f[s[i]]) tot--;
                temp[s[i]]++;
            }
            while(tot == 0 && left <= i){
                
                if(ans > i-left+1){
                    ans = i-left+1;
                    l = left,r = i;
                }

                if(f[s[left]] > 0 && temp[s[left]] >= f[s[left]]){
                    temp[s[left]]--;
                    if(temp[s[left]] < f[s[left]]) tot++;
                }
                left++;
            }
            
        }
        if(ans == n+1) return "";
        return s.substr(l,r-l+1);
    }
};