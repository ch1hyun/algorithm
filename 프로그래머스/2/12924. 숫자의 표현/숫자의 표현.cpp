#include <string>
#include <vector>

using namespace std;

bool binarySearch(int flag, int s, int e) {
    int l = s, r = e;
    while (l <= r) {
        int mid = (l + r) / 2;
        int tmp = mid * (mid + 1);
        if (flag > tmp) l = mid + 1;
        else if (flag < tmp) r = mid - 1;
        else return true;
    }
    
    return false;
}

int solution(int n) {
    int answer = 1;
    
    for (int i = 1; i < n; ++i) {
        if (binarySearch(2 * n + i * (i - 1), i, n)) ++answer;
    }
    
    return answer;
}