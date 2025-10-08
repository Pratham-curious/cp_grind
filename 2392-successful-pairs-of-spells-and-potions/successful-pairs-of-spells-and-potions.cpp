class Solution {
public:
#define ll long long
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(),potions.end());

        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ll val = (success+spells[i]-1LL)/spells[i];
            auto it = lower_bound(potions.begin(),potions.end(),val)-potions.begin();
            ans[i] = m-it;
        }
        return ans;
    }
};