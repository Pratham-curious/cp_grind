class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        vector<vector<int>> point = {{0,0},{n-1,0},{n-1,n-1},{0,n-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){  
                for(auto it : point){ 
                    int sum = 0;
                    int x = it[0] - i,y = it[1]-j;
                    for(int i1=0;i1<n;i1++){
                        for(int j1=0;j1<n;j1++){
                            if(i1+x < n && i1+x >=0 && j1+y < n && j1+y >= 0) sum += (img2[i1][j1] & img1[i1+x][j1+y]);
                        }
                     }
                    ans = max(ans,sum);
                }
            }
        }
        return ans;
    }
};