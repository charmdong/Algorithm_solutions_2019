/**
 * @author : donggun.chung
 * @date : 2020.02.15
 * @site : BOJ
 * @prob_Info : 1926 그림 
 * @time : 24ms
 * @memory : 3048KB
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, area, answer;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dy[4] = {-1, 0, 1 , 0};
int dx[4] = {0, 1, 0, -1};

int bfs(int y, int x);
bool isInBoard(int y, int x);

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    board.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));

    for(int row = 0; row < N; row++) {
        for(int col = 0; col < M; col++) {
            cin >> board[row][col];
        }
    }

    for(int row = 0; row < N; row++) {
        for(int col = 0; col < M; col++) {
            if(board[row][col] == 1 && !visited[row][col]) {
                int res = bfs(row, col);
                
                if(answer < res) {
                    answer = res;
                }
                area++;
            }
        }
    }

    cout << area << endl;
    cout << answer << endl;

    return 0;
}

int bfs(int y, int x) {
    int total = 0;
    queue<pair<int, int>> q;

    q.push({y, x});
    visited[y][x] = true;

    while(!q.empty()) {
        total++;
        pair<int, int> now = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int ny = now.first + dy[dir];
            int nx = now.second + dx[dir];

            if(isInBoard(ny, nx) && board[ny][nx] == 1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }

    return total;
}

bool isInBoard(int y, int x) {
    return (y > -1 && y < N && x > -1 && x < M);
}