class Solution {
public:
/*
observation :
1.every number has root(n) time to calculate all the divisors, to check if the number exist i can use unordered set 


*/

#define ll long long
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        unordered_set<ll> st;
        for(auto it : nums){
            st.insert(it);
        }
        for(auto it : nums){
            ll curr = it;
            for(ll i=1;i*i<=it;i++){
                if(it % i == 0){
                    if(st.find(i) != st.end()) curr = min(i,curr);
                    if(i*i != it){
                        if(st.find(it/i) != st.end()) curr = min(it/i,curr);
                    }
                }
            }
            ans += curr;
        }
        return ans;
    }
};