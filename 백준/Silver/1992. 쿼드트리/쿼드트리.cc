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

int n, board[65][65];

void recursive(int si, int sj, int ei, int ej) {
    int org = board[si][sj];
    bool flag = false;

    for (int i = si; i <= ei && !flag; ++i) {
        for (int j = sj; j <= ej; ++j) {
            if (org != board[i][j]) {
                flag = true;
                break;
            }
        }
    }

    if (flag) {
        int diff = (ei - si + 1) / 2;
        cout << "(";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                recursive(si + diff * i, sj + diff * j, si + diff * (i + 1) - 1, sj + diff * (j + 1) - 1);
            }
        }
        cout << ")";
    } else {
        cout << org;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string w;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> w;
        for (int j = 0; j < n; ++j) {
            board[i][j] = w[j] - '0';
        }
    }

    recursive(0, 0, n - 1, n - 1);

    return 0;
}