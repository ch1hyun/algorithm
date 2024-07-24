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

int L, R, C;
int board[30][30][30];
int dist[30][30][30];
tiii sp, ep;
string a;

int dz[] = {-1, 1, 0, 0, 0, 0};
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 0, 1, -1};

void bfs(tiii s) {
    int visited[L][R][C];
    memset(visited, 0, sizeof(visited));

    queue<tiii> q;
    q.push(sp);
    visited[get<0>(sp)][get<1>(sp)][get<2>(sp)] = 1;

    while(!q.empty()) {
        tiii cur = q.front(); q.pop();

        for (int z = 0; z < 6; ++z) {
            int nz = get<0>(cur) + dz[z], nj = get<1>(cur) + dx[z], ni = get<2>(cur) + dy[z];

            if (0 <= nz && nz < L && 0 <= nj && nj < R && 0 <= ni && ni < C && !board[nz][nj][ni] && !visited[nz][nj][ni]) {
                visited[nz][nj][ni] = 1;
                dist[nz][nj][ni] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                q.push({nz, nj, ni});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    while (true) {
        cin >> L >> R >> C;
        if (!L && !R && !C) break;

        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < R; ++j) {
                cin >> a;
                for (int z = 0; z < C; ++z) {
                    char c = a[z];

                    if (c == '#') {
                        board[i][j][z] = 1;
                    } else if (c == '.') {
                        board[i][j][z] = 0;
                    } else if (c == 'S') {
                        sp = {i, j, z};
                        board[i][j][z] = 0;
                    } else if (c == 'E') {
                        ep = {i, j, z};
                        board[i][j][z] = 0;
                    }
                }
            }
        }

        memset(dist, 0, sizeof(dist));
        bfs(sp);

        if (!dist[get<0>(ep)][get<1>(ep)][get<2>(ep)]) cout << "Trapped!\n";
        else cout << "Escaped in " << dist[get<0>(ep)][get<1>(ep)][get<2>(ep)] << " minute(s).\n";
    }

    return 0;
}