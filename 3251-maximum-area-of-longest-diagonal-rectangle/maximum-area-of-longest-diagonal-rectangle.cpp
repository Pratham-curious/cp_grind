class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxi = 0, dig = 0;
        int n = dimensions.size();
        for(int i=0;i<n;i++){
            int x = dimensions[i][0], y = dimensions[i][1];
            if(x*x+y*y > dig){ 
                maxi = x*y;
                dig = x*x+y*y;
            }
            else if(dig == x*x + y*y) maxi = max(maxi,x*y);
        }
        return maxi;
    }
};