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

int T, h, w, cnt;
int board[102][102];
int visited[102][102];
string tmp;
vector<pii> doors[26];
vector<pii> visitedDoors[26];
map<int, int> key;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

bool rangeIn(int i, int j) {
    return 0 <= i && i <= h + 1 && 0 <= j && j <= w + 1;
}

void bfs() {
    queue<pii> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        pii cur = q.front(); q.pop();

        for (int z = 0; z < 4; ++z) {
            int ni = cur.first + dy[z], nj = cur.second + dx[z];

            if (rangeIn(ni, nj) && !visited[ni][nj]) {
                if (board[ni][nj] == 1) continue;
                if ('A' <= board[ni][nj] && board[ni][nj] <= 'Z') {
                    visitedDoors[board[ni][nj] - 'A'].push_back({ni, nj});
                    continue;
                }
                if ('a' <= board[ni][nj] && board[ni][nj] <= 'z' && !key[board[ni][nj]]) {
                    key[board[ni][nj]] = 1;

                    for (pii pos : doors[board[ni][nj] - 'a']) {
                        board[pos.first][pos.second] = 0;
                    }
                    for (pii pos : visitedDoors[board[ni][nj] - 'a']) {
                        board[pos.first][pos.second] = 0;
                        visited[pos.first][pos.second] = 1;
                        q.push(pos);
                    }
                    
                    visitedDoors[board[ni][nj] - 'a'].clear();
                }

                if (board[ni][nj] == 2) {
                    ++cnt;
                }

                board[ni][nj] = 0;
                visited[ni][nj] = 1;
                q.push({ni, nj});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;
    
    while (T--) {
        // reset
        fill(&board[0][0], &board[101][102], 0);
        fill(&visited[0][0], &visited[101][102], 0);
        for (int i = 0; i < 26; ++i) {
            key[i + 'a'] = 0;
            doors[i].clear();
            visitedDoors[i].clear();
        }
        cnt = 0;

        cin >> h >> w;

        for (int i = 1; i <= h; ++i) {
            cin >> tmp;
            for (int j = 1; j <= w; ++j) {
                char c = tmp[j - 1];

                if (c == '*') {
                    board[i][j] = 1;
                } else if (c == '$') {
                    board[i][j] = 2;
                } else {
                    if ('A' <= c && c <= 'Z') {
                        doors[c - 'A'].push_back({i, j});
                    }

                    board[i][j] = c;
                }
            }
        }

        cin >> tmp;
        if (tmp[0] != '0') {
            for (char c : tmp) {
                key[c] = 1;

                for (pii pos : doors[c - 'a']) {
                    board[pos.first][pos.second] = 0;
                }
            }
        }

        bfs();

        cout << cnt << "\n";
    }

    return 0;
}