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

int n, m, x, y, a, b;
int board[101][101];
int cnt;
vector<pii> light[101][101];

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

bool rangeIn(int i, int j) {
    return 0 < i && i <= n && 0 < j && j <= m;
}

void bfs() {
    board[1][1] = -1;
    cnt = 1;

    queue<pii> q;
    q.push({1, 1});

    while (!q.empty()) {
        pii cur = q.front(); q.pop();

        for (pii l : light[cur.first][cur.second]) {
            if (!board[l.first][l.second]) {
                board[l.first][l.second] = 1;
                ++cnt;

                for (int z = 0; z < 4; ++z) {
                    int ni = l.first + dy[z], nj = l.second + dx[z];
                    if (rangeIn(ni, nj) && board[ni][nj] == -1) {
                        q.push(l);
                        board[l.first][l.second] = -1;
                        break;
                    }
                }
            }
        }

        for (int z = 0; z < 4; ++z) {
            int ni = cur.first + dy[z], nj = cur.second + dx[z];

            if (rangeIn(ni, nj) && board[ni][nj] == 1) {
                board[ni][nj] = -1;
                q.push({ni, nj});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> a >> b;

        light[y][x].push_back({b, a});
    }

    bfs();

    cout << cnt;

    return 0;
}