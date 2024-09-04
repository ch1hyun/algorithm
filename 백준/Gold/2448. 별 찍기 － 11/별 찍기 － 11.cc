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

int N;
char board[3100][6200];
vector<pii> starOffset = {
    {0, 2}, {1, 1}, {1, 3}, {2, 0},
    {2, 1}, {2, 2}, {2, 3}, {2, 4}
};

void recursive(int n, int si, int sj) {
    if (n == 3) {
        for (pii offset : starOffset) {
            board[si + offset.first][sj + offset.second] = '*';
        }

        return;
    }

    recursive(n / 2, si, sj + n / 2);
    recursive(n / 2, si + n / 2, sj);
    recursive(n / 2, si + n / 2, sj + n);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;

    fill(&board[0][0], &board[N][2 * N - 2], 32);
    recursive(N, 0, 0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2 * N - 1; ++j) {
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}