#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;



vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    set<string> names;
    for (string gem : gems) {
        names.insert(gem);
    }
    
    int collectCnt = 0;
    map<string, int> collect;
    
    int l = 0, r = 0;
    int mn = 100000000;
    
    while (l < gems.size() && r < gems.size()) {
        while (r < gems.size() && collectCnt < names.size()) {
            if (!collect[gems[r]]) {
                ++collectCnt;
            }
            ++collect[gems[r]];
            ++r;
        }
        
        while (l < gems.size() && collectCnt == names.size()) {
            --collect[gems[l]];
            if (!collect[gems[l]]) {
                --collectCnt;
            }
            if (collectCnt < names.size() && mn > r - l) {
                mn = r - l;
                answer = {l + 1, r};
            }
            ++l;
        }
    }
    
    return answer;
}