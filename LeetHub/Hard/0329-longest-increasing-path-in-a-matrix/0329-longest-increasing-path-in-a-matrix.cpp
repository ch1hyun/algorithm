class Solution {
public:
    const int dy[4] = {1, -1, 0, 0};
    const int dx[4] = {0, 0, 1, -1};
    vector<vector<int>> dist;
    int n, m;
    int mx = 0;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                bfs(i, j, matrix);
            }
        }

        return mx;
    }

    void bfs(int ci, int cj, vector<vector<int>>& matrix) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({1, ci, cj});
        dist.resize(n);
        for (int i = 0; i < n; ++i) {
            dist[i].resize(m, -1);
        }
        dist[ci][cj] = 0;

        while (!pq.empty()) {
            int curD = get<0>(pq.top());
            int curI = get<1>(pq.top());
            int curJ = get<2>(pq.top());
            pq.pop();

            if (curD < dist[curI][curJ]) continue;

            mx = max(mx, curD);

            for (int z = 0; z < 4; ++z) {
                int ni = curI + dy[z], nj = curJ + dx[z];
                if (rangeIn(ni, nj) && matrix[ni][nj] > matrix[curI][curJ] && dist[ni][nj] < curD + 1) {
                    dist[ni][nj] = curD + 1;
                    pq.push({curD + 1, ni, nj});
                }
            }
        }
    }

    bool rangeIn(int ni, int nj) {
        return 0 <= ni && ni < n && 0 <= nj && nj < m;
    }
};