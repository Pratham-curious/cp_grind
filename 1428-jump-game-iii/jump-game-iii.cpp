class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> qu;
        qu.push(start);

        vector<bool> vis(n,false);
        vis[start] = true;

        while(!qu.empty()){
            int curr = qu.front();
            qu.pop();
            if(arr[curr] == 0) return true;
            int prev = curr - arr[curr];
            int nx = curr + arr[curr];
            if(prev >= 0 && !vis[prev]){
                vis[prev] = true;
                qu.push(prev);
            }
            if(nx < n && !vis[nx]){
                vis[nx] = true;
                qu.push(nx);
            }
        }
        return false;
    }
};