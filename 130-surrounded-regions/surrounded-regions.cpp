class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& board,
             vector<pair<int, int>>& direction, vector<vector<bool>>& vis) {
        int n = board.size(), m = board[0].size();
        vis[x][y] = true;
        for (auto [dx, dy] : direction) {
            int nx = x + dx, ny = y + dy;
            if (nx < n && nx >= 0 && ny < m && ny >= 0) {
                if (!vis[nx][ny] && board[nx][ny] == 'O') {
                    dfs(nx,ny,board,direction,vis);
                }
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<pair<int, int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1  || j == 0 || j == m - 1)) {
                    if (board[i][j] == 'O') {
                        dfs(i,j,board,direction,visited);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};