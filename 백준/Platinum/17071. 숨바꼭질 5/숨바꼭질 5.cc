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

int n, k, bro[500001], sis[2][500001];
int mn[2] = {INF, INF};

bool rangeIn(int i) {
    return 0 <= i && i <= 500000;
}

void bfs() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    sis[0][n] = 0;
    pq.push({sis[0][n], n});

    while (!pq.empty()) {
        int curS = pq.top().first;
        int curN = pq.top().second;
        pq.pop();

        if (curS % 2 == bro[curN] % 2 && curS <= bro[curN]) {
            mn[curS % 2] = min(mn[curS % 2], bro[curN]);
        }

        int nxtS = curS + 1;

        if (rangeIn(curN + 1) && sis[nxtS % 2][curN + 1] == -1) {
            sis[nxtS % 2][curN + 1] = nxtS;
            pq.push({sis[nxtS % 2][curN + 1], curN + 1});
        }

        if (rangeIn(curN - 1) && sis[nxtS % 2][curN - 1] == -1) {
            sis[nxtS % 2][curN - 1] = nxtS;
            pq.push({sis[nxtS % 2][curN - 1], curN - 1});
        }

        if (rangeIn(curN * 2) && sis[nxtS % 2][curN * 2] == -1) {
            sis[nxtS % 2][curN * 2] = nxtS;
            pq.push({sis[nxtS % 2][curN * 2], curN * 2});
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    fill(&bro[0], &bro[500001], -1);
    fill(&sis[0][0], &sis[1][500001], -1);

    for (int curK = k, curS = 0; rangeIn(curK + curS); ++curS) {
        curK += curS;
        bro[curK] = curS;
    }

    bfs();

    if (min(mn[0], mn[1]) == INF) cout << -1;
    else cout << min(mn[0], mn[1]);

    return 0;
}