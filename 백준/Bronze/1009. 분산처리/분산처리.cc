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

ll t, a, b;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> a >> b;

        if (a % 10 == 0 && b != 0) {
            cout << 10 << "\n";
            continue;
        }
        
        ll tmp = 1;
        for (ll i = 0; i < b; ++i) {
            tmp = tmp % 10 * a % 10;
        }

        cout << (tmp - 1) % 10 + 1 << "\n";
    }

    return 0;
}