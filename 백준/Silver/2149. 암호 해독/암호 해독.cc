#include <iostream>
#include <algorithm>
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

string key, word, sortedKey;
int mapper[10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> key >> word;
    sortedKey = key;

    sort(sortedKey.begin(), sortedKey.end());

    fill(mapper, mapper + key.length(), -1);
    for (int i = 0; i < sortedKey.length(); ++i) {
        for (int j = 0; j < key.length(); ++j) {
            if (sortedKey[i] == key[j] && mapper[j] == -1) {
                mapper[j] = i;
                break;
            }
        }
    }

    int colCnt = word.length() / key.length();
    int rowCnt = key.length();

    for (int i = 0; i < colCnt; ++i) {
        for (int j = 0; j < rowCnt; ++j) {
            cout << word[mapper[j] * colCnt + i];
        }
    }

    return 0;
}