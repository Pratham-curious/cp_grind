class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int xmin = n, xmax = 0, ymin = m, ymax = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) if(grid[i][j] == 1) xmax = max(j,xmax);
            for(int j=m-1;j>=0;j--) if(grid[i][j] == 1) xmin = min(j,xmin);
        } 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) if(grid[j][i] == 1) ymax = max(ymax,j);
            for(int j=n-1;j>=0;j--) if(grid[j][i] == 1) ymin = min(ymin,j);
        }
        return (xmax-xmin+1)*(ymax-ymin+1);
    }
};