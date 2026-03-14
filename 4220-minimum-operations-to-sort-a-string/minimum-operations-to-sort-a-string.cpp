class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string b = s;
        sort(b.begin(),b.end());

        if(n == 2) {
            if(s[0] > s[1]) return -1;
            else return 0;
        }

        bool sorted = true, left = (s[0] == b[0]), right = (s[n-1] == b[n-1]);
        for(int i=0;i<n;i++) {
            if(s[i] != b[i]) sorted = false;
        }
        if(sorted) return 0;

        if(left && right && !sorted) return 1;
        if((!left && right) || (!right && left)) return 1;
        if(s[0] == b[n-1] && s[n-1] == b[0]){
            bool found = false;
            for(int i = 0;i<n-1;i++) if(s[n-1] == s[i]) found = true;
            for(int i=n-1;i>0;i--) if(s[0] == s[i]) found = true;
            if(found) return 2;
            else return 3;
        }
        else return 2;
    }
};