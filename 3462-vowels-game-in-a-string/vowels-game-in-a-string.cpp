class Solution {
public:
    bool doesAliceWin(string s) {
        int ans = 0;
        for(auto it : s) ans+= (it == 'a' || it == 'e' || it  =='i' || it =='o' || it == 'u');
        if((ans >0 && ans%2 == 0) || (ans%2 ==1)) return true;
        return false;
    }
};