class Solution {
public:
int mod = 1e9+7;

int count(int n){
    int ans=0;
    while(n > 0){
        ans=(ans+1)%mod;
        n>>=1;
    }
    return ans;
}
    int concatenatedBinary(int n) {
        int ans = 1;
        for(int i=2;i<=n;i++){
            int c = count(i);
            for(int j=0;j<c;j++) ans = (ans*2)%mod;
            ans = (ans+i)%mod;
        }
        return ans;
    }
};