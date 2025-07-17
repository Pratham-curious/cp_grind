class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++) mp[nums[i]%k].push_back(i);
        for(int i=0;i<k;i++){
            if(mp[i].empty()) continue;
            for(int j=0;j<k;j++){
                if(mp[j].empty()) continue;
                int cnt = 1, rev = 1;
                int n1 = mp[i].size() , n2 = mp[j].size();
                int curr = mp[i][0];
                while(curr < n){
                    if(rev == 1){
                        rev = 0;
                        auto it = upper_bound(mp[j].begin(),mp[j].end(),curr) - mp[j].begin();
                        if(it >= n2) break;
                        cnt++;
                        curr = mp[j][it];
                    }
                    else{
                        rev = 1;
                        auto it = upper_bound(mp[i].begin(),mp[i].end(),curr) - mp[i].begin();
                        if(it >= n1) break;
                        cnt++;
                        curr = mp[i][it];
                    }
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};