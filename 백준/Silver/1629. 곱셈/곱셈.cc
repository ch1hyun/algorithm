#include <iostream>
using namespace std;


long long a, b, c;
long long result;

long long f(long long a, long long b, long long c) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		long long result = f(a, b / 2, c);
		return result * result % c;
	}
	else {
		return a * f(a, b - 1, c) % c;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> a >> b >> c;
	cout << f(a, b, c);

	return 0;
}