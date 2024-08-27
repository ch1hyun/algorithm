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

int N, r, c;

void findout(int si, int sj, int ei, int ej, int left, int right) {
    if (si == ei && sj == ej && si == r && sj == c) {
        cout << left;
        return;
    }

    int diffy = (ei - si + 1) >> 1;
    int diffx  = (ej - sj + 1) >> 1;
    int diffn = (right - left + 1) >> 2;

    if (r < si + diffy && c < sj + diffx) {
        findout(si, sj, si + diffy - 1, sj + diffx - 1, left, left + diffn - 1);
    } else if (si + diffy <= r && c < sj + diffx) {
        findout(si + diffy, sj, ei, sj + diffx - 1, left + diffn * 2, left + diffn * 3 - 1);
    } else if (r < si + diffy && sj + diffx <= c) {
        findout(si, sj + diffx, si + diffy - 1, ej, left + diffn, left + diffn * 2 - 1);
    } else {
        findout(si + diffy, sj + diffx, ei, ej, left + diffn * 3, right);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> r >> c;
    findout(0, 0, (1 << N) - 1, (1 << N) - 1, 0, (1 << (N << 1)) - 1);

    return 0;
}