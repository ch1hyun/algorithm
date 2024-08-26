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

int n, m, mx, visited[1000001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    fill(&visited[0], &visited[n + 1], -1);
    int x;
    queue<int> q;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        visited[x] = 0;
        q.push(x);
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i = 0; i < 20; ++i) {
            int nxt = cur ^ (1 << i);

            if (nxt > n || visited[nxt] != -1) continue;
            visited[nxt] = visited[cur] + 1;
            q.push(nxt);
            mx = max(mx, visited[nxt]);
        }
        // int b = 0;
        // while (n >= (cur ^ (1 << b))) {
        //     int nxt = cur ^ (1 << b);
        //     if (visited[nxt] == -1) {
        //         visited[nxt] = visited[cur] + 1;
        //         q.push(nxt);
        //         mx = max(mx, visited[nxt]);
        //     }
        //     ++b;
        // }
    }

    cout << mx;

    return 0;
}