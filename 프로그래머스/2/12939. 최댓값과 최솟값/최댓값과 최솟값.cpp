#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> solve(string s);

string solution(string s) {
    string answer = "";
    
    pair<int, int> ans = solve(s);
    
    return answer + to_string(ans.first) + ' ' + to_string(ans.second);
}

pair<int, int> solve(string s) {
    int mx = -2100000000;
    int mn = 2100000000;
    
    string temp = "";
    for (char c : s) {
        if (c == ' ') {
            int num = stoi(temp);
            mx = max(mx, num);
            mn = min(mn, num);
            temp = "";
        } else {
            temp += c;
        }
    }
    int num = stoi(temp);
    mx = max(mx, num);
    mn = min(mn, num);
    
    return {mn, mx};
}