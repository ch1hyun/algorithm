class Solution {
public:
    vector<vector<int>> visited;
    const int dy[4] = {1, -1, 0, 0};
    const int dx[4] = {0, 0, 1, -1};
    int n, m;

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        visited.resize(n);
        for (int i = 0; i < visited.size(); ++i) {
            visited[i].resize(m, false);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0] && exist(board, word, i, j)) return true;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string &word, int i, int j, int z = 1) {
        if (z == word.length()) return true;

        visited[i][j] = true;

        for (int x = 0; x < 4; ++x) {
            int ni = i + dy[x], nj = j + dx[x];
            if (rangeIn(ni, nj) && !visited[ni][nj] && board[ni][nj] == word[z]) {
                if (exist(board, word, ni, nj, z + 1)) return true;
            }
        }

        visited[i][j] = false;

        return false;
    }

    bool rangeIn(int ni, int nj) {
        return 0 <= ni && ni < n && 0 <= nj && nj < m;
    }
};