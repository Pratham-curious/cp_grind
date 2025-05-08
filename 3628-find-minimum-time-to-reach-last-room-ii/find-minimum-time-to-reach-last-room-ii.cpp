class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> v(n,vector<int>(m,INT_MAX));
        v[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>qu;
        vector<pair<int,int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
        qu.push({0,{0,0}});
        while(!qu.empty()){
            auto it = qu.top();
            qu.pop();
            int dist = it.first;
            int dx = it.second.first , dy = it.second.second;
            for(auto [ix,iy] : direction){
                int nx = dx+ix , ny = dy+iy;
                if(nx >=0 && nx < n && ny >= 0 && ny < m){
                    int inc =((nx + ny) % 2 == 0 ? 2 : 1);
                    if(max(v[dx][dy],moveTime[nx][ny]) + inc < v[nx][ny] ){
                        v[nx][ny] = inc + max(v[dx][dy],moveTime[nx][ny]);
                        qu.push({v[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return v[n-1][m-1];

    }
};