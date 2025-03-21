#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if (a[0] < b[0]) {
        return true;
    } else if (a[0] == b[0]) {
        if (a[1] < b[1]) {
            return true;
        }
    }
    return false;
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), compare);
    int answer = 0;
    
    int l = routes[0][0];
    int r = routes[0][1];
    
    int cur = 1;
    
    while (cur < routes.size()) {
        int cl = routes[cur][0];
        int cr = routes[cur][1];
        
        if (r < cl) {
            ++answer;
            ++cur;
            l = cl, r = cr;
            continue;
        }
        
        l = max(l, cl);
        r = min(r, cr);
        ++cur;
    }
    
    return answer + 1;
}
// [-20, -15] [-18, -13], [-14, -5], [-5, 3]