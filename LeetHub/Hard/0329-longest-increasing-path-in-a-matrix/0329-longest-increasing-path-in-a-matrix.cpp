class Solution {
public:
    int n, m;
    const int dy[4] = {1, -1, 0, 0};
    const int dx[4] = {0, 0, 1, -1};
    vector<vector<int>> len;
    int mx = 0;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        len.resize(n, vector<int>(m, -1));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (len[i][j] == -1) {
                    dfs(i, j, matrix);
                }

                mx = max(mx, len[i][j]);
            }
        }

        return mx;
    }

    int dfs(int ci, int cj, vector<vector<int>>& matrix) {
        if (len[ci][cj] != -1) return len[ci][cj];

        int mxlen = 0;
        for (int z = 0; z < 4; ++z) {
            int ni = ci + dy[z], nj = cj + dx[z];
            
            if (rangeIn(ni, nj) && matrix[ni][nj] > matrix[ci][cj]) {
                mxlen = max(mxlen, dfs(ni, nj, matrix));
            }
        }

        return len[ci][cj] = mxlen + 1;
    }

    bool rangeIn(int ni, int nj) {
        return 0 <= ni && ni < n && 0 <= nj && nj < m;
    }
};