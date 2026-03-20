class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m = grid[0].size();
        vector<vector<int>> v(n-k+1,vector<int>(m-k+1,0));
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                set<int> st;
                for(int i1=0;i1<k;i1++){
                    for(int j1=0;j1<k;j1++){
                        st.insert(grid[i+i1][j+j1]);
                    }
                }
                int val = INT_MAX;
                while(st.size()>1){
                    int top = *st.begin();
                    st.erase(*st.begin());
                    val = min(abs(top-(*st.begin())),val);
                }
                
                v[i][j] = val ==INT_MAX ? 0 : val;
            }
        }
        return v;
    }
};