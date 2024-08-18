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

int r, c, board[1500][1500], dist[1500][1500], visited[1500][1500];

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

vector<pii> edge;
vector<pii> startPos;

bool rangeIn(int i, int j) {
    return 0 <= i && i < r && 0 <= j && j < c;
}

void getEdge(int si, int sj) {
    queue<pii> q;
    visited[si][sj] = 1;
    q.push({si, sj});

    while (!q.empty()) {
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for (int z = 0; z < 4; ++z) {
            int ni = curI + dy[z], nj = curJ + dx[z];

            if (rangeIn(ni, nj) && !visited[ni][nj]) {
                if (board[ni][nj]) {
                    edge.push_back({ni, nj});
                } else {
                    q.push({ni, nj});
                }
                visited[ni][nj] = 1;
            }
        }
    }
}

void getDay() {
    queue<pii> q;

    for (pii e : edge) {
        dist[e.first][e.second] = 1;
        q.push(e);
    }

    while (!q.empty()) {
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for (int z = 0; z < 4; ++z) {
            int ni = curI + dy[z], nj = curJ + dx[z];

            if (rangeIn(ni, nj) && board[ni][nj] && !dist[ni][nj]) {
                dist[ni][nj] = dist[curI][curJ] + 1;
                q.push({ni, nj});
            }
        }
    }
}

void solve() {
    int mn = INF;
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

    visited[startPos[0].first][startPos[0].second] = 0;
    pq.push({0, startPos[0].first, startPos[0].second});

    while(!pq.empty()) {
        int curD, curI, curJ;
        tie(curD, curI, curJ) = pq.top();
        pq.pop();

        if (curD > visited[curI][curJ]) continue;

        for (int z = 0; z < 4; ++z) {
            int ni = curI + dy[z], nj = curJ + dx[z];
            int nxtD = max(curD, dist[ni][nj]);

            if (rangeIn(ni, nj) && (visited[ni][nj] == INF || visited[ni][nj] > nxtD)) {
                visited[ni][nj] = nxtD;
                pq.push({nxtD, ni, nj});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> r >> c;
    string tmp;
    for (int i = 0; i < r; ++i) {
        cin >> tmp;
        for (int j = 0; j < c; ++j) {
            char c = tmp[j];

            if (c == 'L') {
                startPos.push_back({i, j});
            } else if (c == 'X') {
                board[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (!board[i][j] && !visited[i][j]) {
                getEdge(i, j);
            }
        }
    }

    getDay();

    fill(&visited[0][0], &visited[r - 1][c], INF);

    solve();

    cout << visited[startPos[1].first][startPos[1].second];

    return 0;
}