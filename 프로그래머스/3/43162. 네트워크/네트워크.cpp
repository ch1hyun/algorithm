#include <string>
#include <vector>

using namespace std;

void dfs(int cur, vector<vector<int>> &computers, vector<int> &visited) {
    visited[cur] = 1;
    
    for (int j = 0; j < computers[cur].size(); ++j) {
        int nxt = computers[cur][j];
        if (nxt && !visited[j]) {
            dfs(j, computers, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<int> visited(n, 0);
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, computers, visited);
            ++answer;
        }
    }
    
    return answer;
}