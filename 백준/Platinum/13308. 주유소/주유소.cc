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

int N, M, c, u, v, d;
int cost[2501], dist[2501][2501];
vector<pii> edge[2501];

void dijkstra() {
    dist[1][cost[1]] = 0;
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    pq.push({dist[1][cost[1]], 1, 1});

    while (!pq.empty()) {
        int curD = get<0>(pq.top());
        int curMNC = get<1>(pq.top());
        int curN = get<2>(pq.top());
        pq.pop();

        if (curD > dist[curN][cost[curMNC]]) continue;

        for (pii e : edge[curN]) {
            int nxtN = e.first;
            int nxtD = e.second;
            int nxtMNC = cost[curMNC] > cost[nxtN] ? nxtN : curMNC;

            if (dist[nxtN][cost[nxtMNC]] > dist[curN][cost[curMNC]] + cost[curMNC] * nxtD) {
                dist[nxtN][cost[nxtMNC]] = dist[curN][cost[curMNC]] + cost[curMNC] * nxtD;
                

                pq.push({dist[nxtN][cost[nxtMNC]], nxtMNC, nxtN});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    fill(&dist[0][0], &dist[2500][2501], INF);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> cost[i];

    for (int i = 0; i < M; ++i) {
        cin >> u >> v >> d;

        edge[u].push_back({v, d});
        edge[v].push_back({u, d});
    }

    dijkstra();

    int mn = INF;
    for (int i = 0; i <= 2500; ++i) {
        mn = min(mn, dist[N][i]);
    }
    cout << mn;

    return 0;
}