#include<vector>
#include <queue>
using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

bool rangeIn(int n, int m, int ni, int nj) {
    return 0 <= ni & ni < n && 0 <= nj && nj < m;
}

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> dist(n);
    for (int i = 0; i < n; ++i) dist[i].resize(m, -1);
    
    queue<pair<int, int>> q;
    dist[0][0] = 1;
    q.push({0, 0});
    
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        
        for (int z = 0; z < 4; ++z) {
            int ni = cur.first + dy[z], nj = cur.second + dx[z];
            if (rangeIn(n, m, ni, nj) && maps[ni][nj] && dist[ni][nj] == -1) {
                dist[ni][nj] = dist[cur.first][cur.second] + 1;
                q.push({ni, nj});
            }
        }
    }
    
    return dist[n - 1][m - 1];
}