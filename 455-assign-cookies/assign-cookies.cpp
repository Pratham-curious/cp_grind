class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());// boy
        sort(s.begin(),s.end());// cokkie
        int n = g.size(), m = s.size();
        int cnt = 0;
        for(int i=0,j=0;i<n && j<m ;j++){
            if(s[j]>=g[i]){
                cnt++;
                i++;
            }
        }
        return cnt;

    }
};