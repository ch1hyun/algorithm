#include <cstring>
#include <vector>
class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> e;
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        visited.resize(n, false);
        e.resize(n);
        for (auto& edge : edges) {
            e[edge[0]].push_back(edge[1]);
            e[edge[1]].push_back(edge[0]);
        }

        isConnected(source, destination);

        return visited[destination];
    }

    void isConnected(int s, int d) {
        visited[s] = true;
        for (int nxt : e[s]) {
            if (!visited[nxt]) isConnected(nxt, d);
        }
    }
};