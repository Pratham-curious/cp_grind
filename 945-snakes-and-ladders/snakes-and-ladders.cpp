class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q; // {square number, steps}
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();
            if (curr == n * n) return steps;

            for (int move = 1; move <= 6 && curr + move <= n * n; move++) {
                int next = curr + move;
                auto [r, c] = getCoord(next, n);
                if (board[r][c] != -1) {
                    next = board[r][c];
                }

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }
        return -1;
    }

private:
    pair<int, int> getCoord(int num, int n) {
        int r = (num - 1) / n;
        int c = (num - 1) % n;
        if (r % 2 == 1) c = n - 1 - c;
        return {n - 1 - r, c};
    }
};
