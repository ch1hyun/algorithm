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

void recursion(int a, int b, int n) {
    if (n == 1) {
        cout << a << ' ' << b << "\n";
        return;
    }

    recursion(a, 6-a-b, n - 1);
    cout << a << ' ' << b << "\n";
    recursion(6-a-b, b, n - 1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int pow = 1;
    for (int i = 0; i < n; ++i, pow *= 2) {}
    pow -= 1;
    cout << pow << "\n";
    recursion(1, 3, n);

    return 0;
}