#include <iostream>
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

string a;
int b;
string c[20];
int convertDiff = 0;

char convert(char target);

bool check(int num, int index) {
    if (index + c[num].length() > a.length()) return false;
    for (int i = 0; i < c[num].length(); ++i) {
        if (convert(c[num][i]) != a[index + i]) return false;
    }

    return true;
}

char convert(char target) {
    return 97 + (target + convertDiff - 97) % 26;
}

bool search() {
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < a.length(); ++j) {
            if (check(i, j)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> a >> b;
    for (int i = 0; i < b; ++i) {
        cin >> c[i];
    }

    for (int i = 0; i < 26; ++i) {
        if (search()) {
            convertDiff = 26 - convertDiff;
            for (int i = 0; i < a.length(); ++i) {
                cout << convert(a[i]);
            }

            break;
        }

        ++convertDiff;
    }

    return 0;
}