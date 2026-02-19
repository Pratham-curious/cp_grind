class Solution {
public:
    int countBinarySubstrings(string s) {
        int one = s[0] == '1', zero = s[0] == '0';
        int n = s.size(),ans = 0;
        for(int i=1;i<n;i++){
            if(s[i] != s[i-1]) {
                ans += min(one,zero);
                if(s[i] == '0') zero = 1;
                else one = 1;
            }
            else{
            if(s[i] == '0') zero++;
            else one ++;}
            //cout<<"one : "<<one<<", zero : "<<zero<<endl;
            
        }
        ans += min(one,zero);
        return ans;
    }
};