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

ll n, m, a, b, c;
vector<int> v[200001];
ll dist[200001];
ll mnEdge[200001];
map<pii, ll> cost;

void orgdijkstra() {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    fill(&dist[0], &dist[n + 1], llINF);
    dist[1] = 0;
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        ll curD = pq.top().first;
        int curN = pq.top().second;
        pq.pop();

        if (curD > dist[curN]) continue;

        for (int nxt : v[curN]) {
            if (dist[nxt] > dist[curN] + cost[{curN, nxt}]) {
                dist[nxt] = dist[curN] + cost[{curN, nxt}];
                mnEdge[nxt] = cost[{curN, nxt}];
                pq.push({dist[nxt], nxt});
            } else if (dist[nxt] == dist[curN] + cost[{curN, nxt}]) {
                mnEdge[nxt] = min(mnEdge[nxt], cost[{curN, nxt}]);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;

        v[a].push_back(b);
        v[b].push_back(a);

        cost[{a, b}] = c;
        cost[{b, a}] = c;
    }

    orgdijkstra();

    ll sum = 0;
    for (int i = 2; i <= n; ++i) {
        sum += dist[i] / 10LL * 9LL + mnEdge[i] / 10LL;
    }

    cout << sum;

    return 0;
}