class Solution {
public:
    int n = 9, m = 9;
    vector<pair<int, int>> emptySpot;
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == '.') emptySpot.push_back({i, j});
            }
        }

        backtracking(board);
    }

    bool backtracking(vector<vector<char>>& board, int currentSpot = 0) {
        if (currentSpot == emptySpot.size()) return true;

        pair<int, int> currentPos = emptySpot[currentSpot];

        for (int i = 1; i < 10; ++i) {
            if (!check(board, currentPos.first, currentPos.second, i)) continue;
            board[currentPos.first][currentPos.second] = convert2char(i);
            if (backtracking(board, currentSpot + 1)) return true;
            board[currentPos.first][currentPos.second] = '.';
        }

        return false;
    }

    bool check(vector<vector<char>>& board, int i, int j, int num) {
        return rowCheck(board, i, j, num) && colCheck(board, i, j, num) && gridCheck(board, i, j, num);
    }

    bool rowCheck(vector<vector<char>>& board, int i, int j, int num) {
        for (int z = 0; z < m; ++z) {
            if (z == j) continue;
            if (convert2num(board[i][z]) == num) return false;
        }

        return true;
    }

    bool colCheck(vector<vector<char>>& board, int i, int j, int num) {
        for (int z = 0; z < n; ++z) {
            if (z == i) continue;
            if (convert2num(board[z][j]) == num) return false;
        }

        return true;
    }

    bool gridCheck(vector<vector<char>>& board, int i, int j, int num) {
        int si = i / 3 * 3, ei = si + 3;
        int sj = j / 3 * 3, ej = sj + 3;
        
        for (int ci = si; ci < ei; ++ci) {
            for (int cj = sj; cj < ej; ++cj) {
                if (ci == i && cj == j) continue;
                if (convert2num(board[ci][cj]) == num) return false;
            }
        }

        return true;
    }

    int convert2num(char c) {
        return c - '0';
    }

    char convert2char(int num) {
        return (char)(num + '0');
    }
};