#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<vector<bool>> visited;

void solution (vector<vector<int>> board, int y, int x);
bool isInBoard(int y, int x);

int main()
{
    while(true) {
        cin >> m >> n;

        if(n == 0 && m == 0) {
            break;
        }
        
        int ans = 0;
        vector<vector<int>> board(n, vector<int>(m, 0));
        visited.assign(n, vector<bool>(m, false));

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                cin >> board[row][col];
            }
        }

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(!visited[row][col] && board[row][col]) {
                    ans++;
                    solution(board, row, col);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}

void solution (vector<vector<int>> board, int y, int x) {
    visited[y][x] = true;

    for(int dir = 0; dir < 8; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(isInBoard(ny, nx) && !visited[ny][nx] && board[ny][nx]) {
            solution(board, ny, nx);
        }
    }
}

bool isInBoard(int y, int x) {
    if(y > -1 && y < n) {
        if(x > -1 && x < m) {
            return true;
        }
        return false;
    }
    return false;
}