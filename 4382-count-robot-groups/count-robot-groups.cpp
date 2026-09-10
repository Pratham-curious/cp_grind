class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int ans = 0 , n  = position.size();
        int curr = speed[n-1];

        for(int i=n-2;i>=0;i--){
            if(position[i+1] - position[i] <= distance || speed[i] > curr) continue;
            else{
                ans++;
                curr = speed[i];
            }
        }
        return ans+1;
    }
};