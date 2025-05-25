class Solution {
public:
    #define ll long long
    const ll mod = 1e9+7;
    ll expo(ll a,ll b){
        ll res = 1;
        while(b> 0){
            if(b & 1) res =(res*a)%mod;
            a = (a*a) % mod;
            b>>=1;
        }
        return res;
    }
    int search(vector<int>& nums,int low, int tar){
        int high = nums.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]<=tar) {
                low = mid+1;
                ans = mid;
            } else high = mid-1;
        }
        return ans;
    }


    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=target){
                int idx = search(nums,i,target-nums[i]);
                if(idx == -1 ) break;
                ans = (ans+ expo(2,idx-i))%mod;
            }
        }
        return ans;
    }
};