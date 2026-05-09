class Solution {
public:
    /*
    observation :

    -> from each layer tot_new = tot_prev - 8 ;
    -> total size = 2500





    */
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        int l = m, w = n;
        int r = 0, c = 0;
        vector<vector<int>> g(n, vector<int>(m, 0));
        while (l > 0 && w > 0) {
            vector<int> t1;
            for (int i = c; i < c + l - 1; i++) {
               t1.push_back(grid[r][i]);
                //cout<<r<<" , "<<i<<endl;
            }
            for (int j = r; j < r + w - 1; j++) {
                t1.push_back(grid[j][c + l - 1]);
                //cout<<j<<" ,"<<c+l-1<<endl;
            }
            for (int i = c + l - 1; i > c; i--) {
                t1.push_back(grid[r + w - 1][i]);
               // cout<<r+w-1<<", "<<i<<endl;
            }
            for (int j = r + w - 1; j > r; j--) {
                t1.push_back(grid[j][c]);
                //cout<<j<<" , "<<c<<endl;
            }

            // for (auto it : t1)
            //     cout << it << " ";
            // cout << endl;

            int sz = t1.size();
            int idx = 0;
            for (int i = c; i < c + l - 1; i++) {
                g[r][i] = t1[(idx + k) % sz];
                idx++;
            }
            for (int j = r; j < r + w - 1; j++) {
                g[j][c + l - 1] = t1[(idx + k) % sz];
                idx++;
            }
            for (int i = c + l - 1; i > c; i--) {
                g[r + w - 1][i] = t1[(idx + k) % sz];
                idx++;
            }
            for (int j = r + w - 1; j > r; j--) {
                g[j][c] = t1[(idx + k) % sz];
                idx++;
            }
            r++, c++;
            l -= 2;
            w -= 2;
        }
        return g;
    }
};