class Solution {
public:
    int minPartitions(string n) {
        int ans = 0, m = n.size();
        for(int i=0;i<m;i++) ans = max(ans,n[i]-'0');
        return ans;
    }
};