/**
 * @author : donggun.chung
 * @date : 2020.02.23
 * @site : BOJ
 * @prob_Info : 2638 치즈 
 * @time : 12ms
 * @memory : 2120KB
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, answer;
vector<vector<int>> board, visited;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs();
bool removeCheeze();

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    board.assign(N, vector<int>(M, 0));

    for(int row = 0; row < N; row++) {
        for(int col = 0; col < M; col++) {
            cin >> board[row][col];
        }
    }

    while(true) {
        bfs();
        if(!removeCheeze()) {
            break;
        }
        answer++;
    }

    cout << answer << endl;

    return 0;
}

void bfs() {
    queue<pair<int, int>> q;

    visited.assign(N, vector<int>(M, 0));

    visited[0][0] = 1;
    q.push({0, 0});

    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int ny = now.first + dy[dir];
            int nx = now.second + dx[dir];

            if(ny > -1 && ny < N && nx > -1 && nx < M) {
                if(board[ny][nx] == 1) {
                    visited[ny][nx]++;
                } else {
                    if(visited[ny][nx] == 0) {
                        visited[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }
}

bool removeCheeze() {
    vector<pair<int, int>> cheeze;

    for(int row = 0; row < N; row++) {
        for(int col = 0; col < M; col++) {
            if(visited[row][col] > 1) {
                cheeze.push_back({row, col});
            }
        }
    }

    if(cheeze.size() == 0) {
        return false;
    }

    for(pair<int, int> pos : cheeze) {
        board[pos.first][pos.second] = 0;
    }

    return true;
}