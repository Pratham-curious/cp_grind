class Solution {
public:
#define ll long long
const ll M = 1e15;
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return -1;

        vector<ll> v(n,0);
        v[0] = nums[0];
        for(int i=1;i<n;i++) v[i] = v[i-1]+nums[i];

        ll product = 1, ans = -1;
        if(v[n-2] == 1) ans = n-1;
        for(int i=n-2;i>= 0;i--){
            if(nums[i+1] == 0 || product == 0) product = 0;
            else if(product < M/nums[i+1]) product *= nums[i+1];
            else break;

            if(i >0  && product == v[i-1]) ans = i;
            else if(i == 0 && product == 0) ans = 0;
        }

        return ans;

    }
};