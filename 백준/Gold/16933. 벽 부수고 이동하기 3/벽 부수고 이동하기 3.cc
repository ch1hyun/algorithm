#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define MAX 1000000000
#define all(x) (x).begin(), (x).end()
#define mp(x) make_pair(x)

const int INF = 2100000000;
const ll llINF = 1e18;

string a;
int n, m, k, board[1001][1001], dist[11][1001][1001];

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
const int DAY = 0;
const int NIGHT = 1;

bool rangeIn(int i, int j) {
    return 0 < i && i <= n && 0 < j && j <= m;
}

void bfs() {
    queue<tuple<int, int, int, int, int>> q;
    q.push({k, 1, 1, DAY, 0});
    dist[k][1][1] = 1;

    while (!q.empty()) {
        int curK = get<0>(q.front());
        int curI = get<1>(q.front());
        int curJ = get<2>(q.front());
        int curT = get<3>(q.front());
        int curS = get<4>(q.front());
        q.pop();

        for (int z = 0; z < 4; ++z) {
            int ni = curI + dy[z], nj = curJ + dx[z];
            if (rangeIn(ni, nj)) {
                if (board[ni][nj]) {
                    if (curK && !dist[curK - 1][ni][nj]) {
                        if (curT == DAY) {
                            dist[curK - 1][ni][nj] = dist[curK][curI][curJ] + 1 + curS;
                            q.push({curK - 1, ni, nj, NIGHT, dist[curK - 1][ni][nj]});
                        } else {
                            q.push({curK, curI, curJ, DAY, 1});
                        }
                    }
                } else {
                    if (!dist[curK][ni][nj]) {
                        dist[curK][ni][nj] = dist[curK][curI][curJ] + 1;
                        q.push({curK, ni, nj, curT == DAY ? NIGHT : DAY, 0});
                    }
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    fill(&dist[0][0][0], &dist[k][n][m + 1], 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a;

        for (int j = 1; j <= m; ++j) {
            board[i][j] = a[j - 1] - '0';
        }
    }

    bfs();

    int mn = INF;
    for (int i = 0; i <= k; ++i) {
        if (dist[i][n][m]) {
            mn = min(mn, dist[i][n][m]);
        }
    }

    if (mn == INF) cout << -1;
    else cout << mn;

    return 0;
}