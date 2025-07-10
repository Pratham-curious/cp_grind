class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(),  m = heights[0].size();
        vector<vector<int>> minEffort(n,vector<int>(m,INT_MAX));
        minEffort[0][0] = 0;
        vector<pair<int,int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
        using T = pair<int,pair<int,int>>;
        priority_queue<T,vector<T>,greater<T>> pq;

        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto [currEff,coord] = pq.top();
            auto [x,y] = coord;
            pq.pop();

            if(currEff > minEffort[x][y]) continue;

            for(auto [dx,dy] : direction){
                int nx = x+dx, ny = y+dy;
                if(nx >= 0 && nx < n && ny < m && ny>=0){
                    int diffHeight = abs(heights[nx][ny]-heights[x][y]);
                    if(max(diffHeight,currEff) < minEffort[nx][ny]){
                        minEffort[nx][ny] = max(diffHeight,currEff);
                        pq.push({minEffort[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return minEffort[n-1][m-1];

    }
};