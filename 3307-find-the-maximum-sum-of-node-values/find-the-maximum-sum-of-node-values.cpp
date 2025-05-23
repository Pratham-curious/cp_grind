class Solution {
public:
    #define ll long long
    #define pb push_back

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<pair<ll,ll>> maxi,mini;
        ll sum = 0;
        for(auto it : nums) sum+=it;
        for(int i=0;i<n;i++){
            if((nums[i]^k) > nums[i]) maxi.pb({((nums[i]^k)-nums[i]),i});
            else mini.pb({(nums[i]-(nums[i]^k)),i});
            
        }
        sort(maxi.begin(),maxi.end());
        sort(mini.begin(),mini.end());
        for(auto it : maxi) sum+=it.first;
        if(maxi.size() & 1){
            if(!mini.empty()){
                if(maxi[0].first > mini[0].first) {
                    sum -= mini[0].first;
                }
                else{
                    sum -=maxi[0].first;
                }
            }
            else{
                sum -=maxi[0].first;
            }
        }
        return sum;
    }
};