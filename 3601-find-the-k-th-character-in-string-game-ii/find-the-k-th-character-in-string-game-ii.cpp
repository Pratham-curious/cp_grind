class Solution {
public:
#define ll long long
    ll val(ll k) {
        ll curr = 1, jmp = 0;
        while (curr * 2 < k) {
            jmp++;
            curr *= 2;
        }
        return jmp;
    }
    char kthCharacter(long long k, vector<int>& operations) {
        ll cnt = 0;
        if(k == 1) return 'a';
        ll idx = val(k);
        while(k!=1){
            k%=(1ll<<idx);
            if(k == 0) k = (1ll<<idx);
            cnt += operations[idx];
            idx = val(k);
        }
        return 'a' + cnt % 26;
    }
};