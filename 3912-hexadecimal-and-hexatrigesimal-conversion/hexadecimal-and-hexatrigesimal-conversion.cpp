class Solution {
public:
    string hex(int n,int base){
        string ans ="";
        while(n>0){
            int rem = n%base;
            n/=base;
            if(rem <= 9) ans+='0'+rem;
            else ans += 'A'+rem-10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string concatHex36(int n) {
        string ans;
        ans = hex(n*n,16) + hex(n*n*n,36);
        return ans;
    }
};