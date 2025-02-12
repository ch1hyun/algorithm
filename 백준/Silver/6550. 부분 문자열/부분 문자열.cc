#include <iostream>
#include <cstring>
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    while (1) {
        string a;
        string b;
        cin >> a >> b;
        if (cin.eof()) break;

        int i = 0;
        int cnt = 0;
        for (char c : b) {
            if (c == a[i]) {
                ++i;
                ++cnt;
            }
        }

        if (cnt == a.length()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}