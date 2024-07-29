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

int N, board[100][100], dist[100][100];
int groupId = 0;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int minBridge = INF;

void grouping(pii s) {
    queue<pii> q;
    q.push(s);
    board[s.first][s.second] = ++groupId;

    while (!q.empty()) {
        pii cur = q.front(); q.pop();

        for (int z = 0; z < 4; ++z) {
            int ni = cur.first + dy[z], nj = cur.second + dx[z];

            if (0 <= ni && ni < N && 0 <= nj && nj < N && board[ni][nj] == -1) {
                board[ni][nj] = groupId;
                q.push({ni, nj});
            }
        }
    }
}

void getBridge(int startGroupNum, pii s) {
    queue<pii> q;

    dist[s.first][s.second] = 0;
    q.push(s);

    while (!q.empty()) {
        pii cur = q.front(); q.pop();

        for (int z = 0; z < 4; ++z) {
            int ni = cur.first + dy[z], nj = cur.second + dx[z];

            if (0 <= ni && ni < N && 0 <= nj && nj < N) {
                if (board[ni][nj] == startGroupNum) {
                    if (dist[ni][nj]) {
                        dist[ni][nj] = 0;
                        q.push({ni, nj});
                    }
                } else if (!board[ni][nj]) {
                    if (dist[ni][nj] > dist[cur.first][cur.second] + 1) {
                        dist[ni][nj] = dist[cur.first][cur.second] + 1;
                        q.push({ni, nj});
                    } 
                } else {
                    minBridge = min(minBridge, dist[cur.first][cur.second]);
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];

            if (board[i][j]) board[i][j] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == -1) {
                grouping({i, j});
            }
        }
    }

    fill(&dist[0][0], &dist[N - 1][N - 1], INF);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] && dist[i][j]) {
                getBridge(board[i][j], {i, j});
            }
        }
    }

	cout << minBridge;

    return 0;
}