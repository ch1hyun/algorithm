#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

vector<vector<int>> visited;
vector<vector<int>> board;

int cnt;

bool rangeIn(int ni, int nj) {
    return 0 <= ni && ni < board.size() && 0 <= nj && nj < board[ni].size();
}

void dfs(int i, int j) {
    cnt += board[i][j];
    visited[i][j] = 1;
    
    for (int z = 0; z < 4; ++z) {
        int ni = i + dy[z], nj = j + dx[z];
        if (rangeIn(ni, nj) && board[ni][nj] != -1 && !visited[ni][nj]) {
            dfs(ni, nj);
        }
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    visited.resize(maps.size(), {});
    board.resize(maps.size(), {});
    
    for (int i = 0; i < maps.size(); ++i) {
        for (char c : maps[i]) {
            visited[i].push_back(0);
            if (c == 'X') {
                board[i].push_back(-1);
            } else {
                board[i].push_back(c - '0');
            }
        }
    }
    
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] != -1 && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                answer.push_back(cnt);
            }
        }
    }
    
    if (!answer.size()) return {-1};
    
    sort(answer.begin(), answer.end());
    
    return answer;
}