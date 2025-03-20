#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

vector<vector<int>> board;
vector<vector<int>> dist;

bool rangeIn(int ni, int nj) {
    return 0 < ni && ni < 102 && 0 < nj && nj < 102;
}

bool isInside(vector<vector<int>> &rectangle, int i, int j) {
    for (vector<int> r : rectangle) {
        int si = r[0] << 1, sj = r[1] << 1, ei = r[2] << 1, ej = r[3] << 1;
        if (si < i && i < ei && sj < j && j < ej) return true;
    }
    
    return false;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    board.resize(102);
    dist.resize(102);
    for (int i = 0; i < 102; ++i) {
        board[i].resize(102, 0);
        dist[i].resize(102, -1);
    }
    
    for (vector<int> r : rectangle) {
        int si = r[0] << 1, sj = r[1] << 1, ei = r[2] << 1, ej = r[3] << 1;
        
        for (int i = si; i <= ei; ++i) {
            if (!isInside(rectangle, i, sj)) {
                board[i][sj] = 1;
            }
            if (!isInside(rectangle, i, ej)) {
                board[i][ej] = 1;
            }
        }
        
        for (int j = sj; j <= ej; ++j) {
            if (!isInside(rectangle, si, j)) {
                board[si][j] = 1;
            }
            if (!isInside(rectangle, ei, j)) {
                board[ei][j] = 1;
            }
        }
    }

    itemX <<= 1;
    itemY <<= 1;
    characterX <<= 1;
    characterY <<= 1;
    queue<pair<int, int>> q;
    q.push({characterX, characterY});
    dist[characterX][characterY] = 0;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        if (curX == itemX && curY == itemY) {
            return dist[curX][curY] >> 1;
        }
        
        for (int z = 0; z < 4; ++z) {
            int ni = curX + dx[z], nj = curY + dy[z];
            if (rangeIn(ni, nj) && board[ni][nj] && dist[ni][nj] == -1) {
                q.push({ni, nj});
                dist[ni][nj] = dist[curX][curY] + 1;
            }
        }
    }
    
    return answer;
}