#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> edges;


bool isConnect(string a, string b) {
    int cnt = 0;
    
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i] && ++cnt > 1) return false;
    }
    
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    edges.resize(words.size() + 1);
    
    int beginNum = words.size();
    words.push_back(begin);
    int targetNum = -1;
    
    for (int i = 0; i < words.size(); ++i) {
        if (words[i] == target) targetNum = i;
        for (int j = i + 1; j < words.size(); ++j) {
            if (isConnect(words[i], words[j])) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }
    
    if (targetNum == -1) return 0;
    
    vector<int> dist(words.size(), -1);
    queue<int> q;
    q.push(beginNum);
    dist[beginNum] = 0;
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == targetNum) return dist[cur];
        
        for (int nxt : edges[cur]) {
            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
    
    return 0;
}