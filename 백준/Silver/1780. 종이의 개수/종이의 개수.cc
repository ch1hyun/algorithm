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

int cnt[3];
int n, board[2200][2200];

void count(int si, int sj, int ei, int ej) {
    int org = board[si][sj];
    bool flag = false;
    for (int i = si; i <= ei; ++i) {
        for (int j = sj; j <= ej; ++j) {
            if (board[i][j] != org) {
                flag = true;
                break;
            }
        }
    }

    if (flag) {
        int diff = (ei - si + 1) / 3;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                count(si + i * diff, sj + j * diff, si + (i + 1) * diff - 1, sj + (j + 1) * diff - 1);
            }
        }
        return;
    }

    ++cnt[org + 1];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    count(0, 0, n - 1, n - 1);

    for (int i = 0; i < 3; ++i) {
        cout << cnt[i] << "\n";
    }

    return 0;
}