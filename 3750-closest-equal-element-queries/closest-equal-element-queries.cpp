class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int,set<int>> mp;
        int n = nums.size();
        for(int i=0;i<n;i++) mp[nums[i]].insert(i);
        vector<int> ans;
        for(auto it : queries){
            int val = nums[it];
            auto idx = mp[val].find(it);

            int low = n, high = n;

            if(mp[val].size() == 1){
                ans.push_back(-1);
            }
            else{

                if(idx != mp[val].begin()){
                    auto pre = prev(idx);
                    low = *idx - *pre;
                }
                else{
                    low = n - (*mp[val].rbegin() - *idx);
                }
                auto nx = next(idx);
                if(nx != mp[val].end()){
                    high =  *nx - *idx;
                }
                else{
                    high = n - (*idx - *mp[val].begin());
                }
                ans.push_back(min(low,high));
            }


        }
        return ans;
    }
};