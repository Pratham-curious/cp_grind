class Solution {
public:
    #define ll long long
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m = n/3;
        vector<ll> mini(n,0), maxi(n,0);
        multiset<int> st;
        ll sum = 0;
        for(int i=n-1;i>=0;i--){
            st.insert(nums[i]);
            sum+=nums[i];
            if(st.size()>m){
                sum-=*st.begin();
                st.erase(st.begin());
            }
            if(st.size()!= m) maxi[i] = LLONG_MIN;
            else maxi[i] = sum;
        }
        while(!st.empty()){
            st.erase(st.begin());
        }
        sum = 0;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
            sum+=nums[i];
            if(st.size()>m){
                sum-=*st.rbegin();
                st.erase(st.find(*st.rbegin()));
            }
            if(st.size()!= m) mini[i] = LLONG_MAX;
            else mini[i] = sum;
        }
        ll ans = LLONG_MAX;
        for(int i=m-1;i<n-m;i++){
            if(mini[i] == LLONG_MAX || maxi[i+1] == LLONG_MIN) continue;
            ans = min(ans,mini[i]-maxi[i+1]);
        }
        return ans;
    }
};