class Solution {
public:
    #define ll long long
    bool canPartition(vector<int>& nums) {
        ll sum = accumulate(nums.begin(),nums.end(),0ll);
        if(sum & 1) return false;
        ll tar = sum/2;
        vector<bool> temp(tar+1,false);
        for(auto it : nums){
            for(int i=temp.size()-1;i>=0;i--){
                if(temp[i] && i+it<temp.size()) temp[i+it]=true;
            }
            if(it<temp.size())temp[it]=true;
        }
        return temp[tar];
    }
};