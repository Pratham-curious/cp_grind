class Solution {
public:
    int maxDifference(string s) {
        vector<int> alp(26,0);
        int even = INT_MAX, odd = 0;
        for(auto it : s) alp[it-'a']++;
        for(auto it : alp){
            if(it % 2 == 0 && it != 0 ) even = min(even,it);
            else odd = max(odd,it);
        }
        return odd - even;
    }
};