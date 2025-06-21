class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> alp(26,0);
        for(auto it : word) alp[it-'a']++;
        sort(alp.begin(),alp.end());

        vector<int> pref(26,0);
        pref[0] = alp[0];
        for(int i=1;i<26;i++) pref[i] = pref[i-1]+alp[i];

        int left = 0;
        int maxi = INT_MAX;
        for(int i=0;i<26;i++){
            if(alp[i] == 0) continue;
            while(left < 26 && alp[left] <= k+alp[i]) left++;
            maxi = min(maxi , (i>0 ? pref[i-1] : 0) + (pref[25]-pref[left-1])-(26-left)*(k+alp[i]));
        }
        return maxi;



    }
};