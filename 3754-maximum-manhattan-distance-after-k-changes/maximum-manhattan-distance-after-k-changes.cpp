class Solution {
public:
    int maxDistance(string s, int k) {
        int N=0,S=0,E=0,W=0;
        int maxi = 0,curr = 0;

        for(auto it : s){
            if(it == 'N') N++;
            else if(it == 'S') S++;
            else if(it == 'W') W++;
            else E++;
            maxi = max(maxi,abs(N-S)+abs(E-W)+2*min(k,min(N,S)+min(E,W)));
        }
        return maxi;
    }
};