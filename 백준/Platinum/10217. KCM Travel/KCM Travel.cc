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

int T, N, M, K,u, v, c, d;
int dist[101][10001];

vector<tiii> edge[101];

void dijkstra() {
    dist[1][0] = 0;
    queue<tiii> q;
    q.push({0, 0, 1});

    while (!q.empty()) {
        int curT = get<0>(q.front());
        int curD = get<1>(q.front());
        int curN = get<2>(q.front());
        q.pop();

        if (curD > dist[curN][curT]) continue;

        for (tiii e : edge[curN]) {
            int nxtN = get<0>(e);
            int nxtT = get<1>(e);
            int nxtD = get<2>(e);

            int time = curT + nxtT;

            if (time > M) continue;

            if (dist[nxtN][time] > dist[curN][curT] + nxtD) {
                dist[nxtN][time] = dist[curN][curT] + nxtD; 
                q.push({time, dist[nxtN][time], nxtN});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;

    while (T--) {
        fill(&dist[0][0], &dist[100][10001], INF);

        cin >> N >> M >> K;

        for (int i = 0; i < K; ++i) {
            cin >> u >> v >> c >> d;
            edge[u].push_back({v, c, d});
        }

        dijkstra();

        int mn = INF;
        for (int i = 1; i <= M; ++i) {
            mn = min(mn, dist[N][i]);
        }

        if (mn == INF) cout << "Poor KCM";
        else cout << mn;

        for (int i = 1; i <= N; ++i) {
            edge[i].clear();
        }
    }

    return 0;
}