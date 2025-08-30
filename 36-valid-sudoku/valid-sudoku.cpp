class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<bool> vis(10, false);
            for (int j = 0; j < 9; j++) {
                int n = board[i][j]-'0';
                if(n < 0) continue;
                if (vis[n])
                    return false;
                vis[n] = true;
            }
        }
        for (int i = 0; i < 9; i++) {
            vector<bool> vis(9, false);
            for (int j = 0; j < 9; j++) {
                int n = board[j][i]-'0';
                 if(n < 0) continue;
                if (vis[n])
                    return false;
                vis[n]= true;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<bool> vis(9, false);  
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        int n = board[x][y]-'0';
                         if(n < 0) continue;
                        if (vis[n])
                              return false;
                        vis[n] = true;
                    }
                }
            }
        }
        return true;
    }
};