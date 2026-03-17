class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int ans = 0;
        int a1 = 0, a2 = 0; /// a1 -> 101 ,a2 -> 010

        /*
        110
        -101

1010
-0101
--1010
---1010




        */
        vector<int> s1(n,0),s2(n,0);
        for(int i=0;i<n;i++){
            if(i % 2 == 0){
                if(s[i] == '0')a1++;
                else a2++;
            }
            else{
                if(s[i] == '0')a2++;
                else a1++;
            }
            s1[i] = a1;
            s2[i] = a2;
        }
        ans = min(a1,a2);

        if(n & 1){
            int sum = 0;
            for(int i=0;i<n-1;i++){
                ans = min(ans,a1-s1[i]+s2[i]);
                ans = min(ans,a2-s2[i]+s1[i]);
            }
        }
        return ans;




    }
};