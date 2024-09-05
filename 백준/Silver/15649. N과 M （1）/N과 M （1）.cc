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

int n, m, check[9];
vector<int> v;

void backtracking() {
    if (v.size() == m) {
        for (int num : v) {
            cout << num << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!check[i]) {
            check[i] = 1;
            v.push_back(i);
            backtracking();
            v.pop_back();
            check[i] = 0;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    backtracking();

    return 0;
}