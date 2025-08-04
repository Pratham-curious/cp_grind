class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n = fruits.size();
        int ans = 0,left = 0;
        for(int i=0;i<n;i++){
            mp[fruits[i]]++;
            while(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};