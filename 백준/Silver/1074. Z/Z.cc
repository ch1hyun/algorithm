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

int findout(int n, int r, int c) {
    if (!n) return 0;

    int half = 1 << (n - 1);

    if (r < half && c < half) return findout(n - 1, r, c);
    else if (r < half && half <= c) return half * half + findout(n - 1, r, c - half);
    else if (half <= r && c < half) return half * half * 2 + findout(n - 1, r - half, c);
    else return half * half * 3 + findout(n - 1, r - half, c - half);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> r >> c;
    cout << findout(N, r, c);

    return 0;
}