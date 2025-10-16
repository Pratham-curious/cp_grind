class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int> mp;
        int n = nums.size();
        for(auto it : nums){
            int f = ((it%value) + value)%value;
            
            mp[f]++;
        }
        for(auto it : mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        for(int i=0;i<=n;i++){
            int f = i%value;
            if(mp.find(f) == mp.end() || mp[f] == 0) return i;
            mp[f]--;
        }
        return 0;
        
    }
};