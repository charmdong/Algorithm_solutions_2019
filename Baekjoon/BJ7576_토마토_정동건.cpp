/**
 * @author : donggun.chung
 * @date : 2020.02.12
 * @site : BOJ
 * @prob_Info : 7576 토마토 
 * @time : 252ms
 * @memory : 14MB
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, answer;
vector<vector<int>> board, days;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void solution();
bool isInBoard(int y, int x);
bool check();

int main()
{
    cin >> N >> M;
    board.assign(M, vector<int>(N, 0));
    days.assign(M, vector<int>(N, 0));
    visited.assign(M, vector<bool>(N, false));

    for(int row = 0; row < M; row++) {
        for(int col = 0; col < N; col++) {
            cin >> board[row][col];

            if(board[row][col] == 1) {
                visited[row][col] = true;
                q.push({row, col});
            }
        }
    }

    solution();
    answer = (check()) ? answer : -1;
    cout << answer << endl;

    return 0;
}

void solution() {
    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int ny = now.first + dy[dir];
            int nx = now.second + dx[dir];

            if(isInBoard(ny, nx) && board[ny][nx] == 0) {
                if(!visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                    board[ny][nx] = 1;
                    answer = days[ny][nx] = days[now.first][now.second] + 1;
                }
            }            
        }
    }
}

bool isInBoard(int y, int x) {
    return (y > -1 && y < M && x > -1 && x < N);
}

bool check() {
    for(int row = 0; row < M; row++) {
        for(int col = 0; col < N; col++) {
            if(board[row][col] == 0) {
                return false;
            }
        }
    }

    return true;
}