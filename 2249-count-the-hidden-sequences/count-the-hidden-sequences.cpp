class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long high = 0, low = 0;
        long long ans = 0;
        for(auto it : differences) {
            ans+=it;
            high = max(ans,high);
            low = min(ans,low);
        }
        return max(0LL,(upper-high)-(lower-low)+1);
    }
};