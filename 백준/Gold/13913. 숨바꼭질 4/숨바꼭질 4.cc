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

int n, k, board[100001], from[100001];

bool rangeIn(int p) {
    return 0 <= p && p <= 100000;
}

void bfs() {
    queue<int> q;

    q.push(n);
    board[n] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (rangeIn(cur * 2) && board[cur * 2] > board[cur] + 1) {
            board[cur * 2] = board[cur] + 1;
            from[cur * 2] = cur;
            q.push(cur * 2);
        }
        if (rangeIn(cur + 1) && board[cur + 1] > board[cur] + 1) {
            board[cur + 1] = board[cur] + 1;
            from[cur + 1] = cur;
            q.push(cur + 1);
        }
        if (rangeIn(cur - 1) && board[cur - 1] > board[cur] + 1) {
            board[cur - 1] = board[cur] + 1;
            from[cur - 1] = cur;
            q.push(cur - 1);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    fill(&board[0], &board[100001], INF);
    fill(&from[0], &from[100001], -1);

    cin >> n >> k;

    bfs();

    cout << board[k] << "\n";
    stack<int> s;
    int cur = k;
    do {
        s.push(cur);
        cur = from[cur];
    } while (cur != -1);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}