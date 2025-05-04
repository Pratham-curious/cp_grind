class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        int n = dominoes.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int mini = min(dominoes[i][0],dominoes[i][1]);
            int maxi = max(dominoes[i][1],dominoes[i][0]);
            mp[maxi + 10*mini]++;
        }
        for(auto it : mp){
            count += ((it.second)*(it.second-1))/2;
        }
        return count;
    }
};