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

int n, m, p;
int s[10], c[10];
int board[1000][1000];
bool isStretch;
string a;
vector<pii> boundary[10];

const int dy[] = {-1, 0, 0, 1};
const int dx[] = {0, 1, -1, 0};

bool rangeIn(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

void stretch(int num, vector<pii> v) {
    queue<tuple<int, int, int>> q;

    for (pii cur : v) {
        q.push({s[num], cur.first, cur.second});
    }

    boundary[num].clear();

    while (!q.empty()) {
        int curMv = get<0>(q.front());
        int curI = get<1>(q.front());
        int curJ = get<2>(q.front());
        q.pop();

        if (!curMv) {
            for (int z = 0; z < 4; ++z) {
                int ni = curI + dy[z], nj = curJ + dx[z];

                if (rangeIn(ni, nj) && !board[ni][nj]) {
                    boundary[num].push_back({curI, curJ});
                    break;
                }
            }
            continue;
        }

        for (int z = 0; z < 4; ++z) {
            int ni = curI + dy[z], nj = curJ + dx[z];

            if (rangeIn(ni, nj) && !board[ni][nj]) {
                board[ni][nj] = num;
                ++c[num];
                isStretch = true;
                q.push({curMv - 1, ni, nj});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m >> p;
    for (int i = 1; i <= p; ++i) cin >> s[i];

    for (int i = 0; i < n; ++i) {
        cin >> a;
        for (int j = 0; j < m; ++j) {
            char ca = a[j];

            if (ca == '.') {
                board[i][j] = 0;
            } else if (ca == '#') {
                board[i][j] = 10;
            }else {
                board[i][j] = ca - '0';
                c[board[i][j]]++;
                boundary[board[i][j]].push_back({i, j});
            }
        }
    }

    isStretch = true;
    while (isStretch) {
        isStretch = false;

        for (int i = 1; i <= p; ++i) {
            stretch(i, boundary[i]);
        }
    }

    for (int i = 1; i <= p; ++i) {
        cout << c[i] << " ";
    }

    return 0;
}