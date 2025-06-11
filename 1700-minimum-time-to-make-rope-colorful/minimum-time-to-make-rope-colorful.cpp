class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int sum = 0, maxi = 0;
        char ch='0';
        int n = colors.size();
        for(int i=0;i<n;i++){
            if(colors[i] != ch){
                ans += sum-maxi;
                sum = neededTime[i];
                maxi = sum;
                ch = colors[i];
            }
            else{
                sum+=neededTime[i];
                maxi = max(maxi,neededTime[i]);
            }
        }
        ans += sum-maxi;
        return ans;
    }
};