#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long l = 0, r = 90000000000000000;
    
    while (l <= r) {
        long long mid = (l + r) / 2;
        
        long long sum = 0;
        for (int t : times) sum += mid / t;
        
        if (sum >= n) {
            r = mid - 1;
        } else if (sum < n) {
            l = mid + 1;
        }
    }
    
    return l;
}