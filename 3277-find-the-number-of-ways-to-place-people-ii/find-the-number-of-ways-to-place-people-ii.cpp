class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int ans = 0, n = points.size();
        for(int i=0;i<n;i++){
            int x1 = points[i][0], y1 = points[i][1];
            int ymin = INT_MIN;
            for(int j=i+1;j<n;j++){
                int x2 = points[j][0], y2 = points[j][1];
                if(y2 <= y1 && y2 > ymin){
                   // cout<<"I :" <<i<<" J: "<<j<<endl;
                    ymin = y2;
                    ans++;
                }
                //else break;

            }
        }
        return ans;
    }
};