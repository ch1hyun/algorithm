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

int t, n, cnt, board[100001], visited[100001];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    stack<int> st;
    visited[s] = 1;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        st.push(cur);

        int nxt = board[cur];
        if (visited[nxt]) {
            int tmp, tmpCnt = 0;
            while (!st.empty()) {
                tmp = st.top(); st.pop();
                ++tmpCnt;
                if (tmp == nxt) {
                    break;
                }
            }
            if (tmp == nxt) {
                cnt -= tmpCnt;
            }
            break;
        } else {
            visited[nxt] = 1;
            q.push(nxt);
        }
    }

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        cin >> n;
        cnt = n;
        memset(visited, 0, sizeof(visited));

        for (int i = 1; i <= n; ++i) {
            cin >> board[i];
        }

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                bfs(i);
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}