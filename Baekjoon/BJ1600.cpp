/**
 * @author : donggun.chung
 * @date : 2020.02.08
 * @site : BOJ 
 * @prob_Info : 1600 말이 되고픈 원숭이 
 * @time : 76ms
 * @memory : 3464KB
 */

#include <iostream>
#include <vector>
#include <queue>
#define MAX 200
using namespace std;

int solution();

int k, w, h;
vector<vector<int>> board;
bool visited[MAX][MAX][31];

int dy[12] = {-1, 0, 1, 0};
int dx[12] = {0, 1, 0, -1};
int hy[8] = {-2, -1, 1, 2, 2, 1, -1, 2};
int hx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int kCnt, int y = 0, int x = 0);
bool isInBoard(int y, int x);

int main()
{
    cin >> k >> w >> h;

    board.assign(h, vector<int>(w, 0));

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            cin >> board[row][col];
        }
    }

    cout << bfs(k) << endl;

    return 0;
}

int bfs(int k, int y, int x) {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    
    q.push({{y, x},{0, 0}});
    visited[y][x][0] = true;

    while(!q.empty()) {
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int cnt = q.front().second.first;
        int knight = q.front().second.second;
        q.pop();

        if(curY == h - 1 && curX == w - 1) {
            return cnt;
        }

        if(knight < k) {
            for(int dir = 0; dir < 8; dir++) {
                int ny = curY + hy[dir];
                int nx = curX + hx[dir];

                if(isInBoard(ny, nx)) {
                    // ny, nx까지 knight + 1번의 능력을 사용해 도착한 경우
                    if(board[ny][nx] == 0 && !visited[ny][nx][knight + 1]) {
                        visited[ny][nx][knight + 1] = true;
                        q.push({{ny, nx}, {cnt + 1, knight + 1}});
                    }
                }
            }
        }

        for(int dir = 0; dir < 4; dir++) {
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];

            if(isInBoard(ny, nx)) {
                if(board[ny][nx] == 0 && !visited[ny][nx][knight]) {
                    visited[ny][nx][knight] = true;
                    q.push({{ny, nx}, {cnt + 1, knight}});
                }
            }
        }
    }

    return -1;
}

bool isInBoard(int y, int x) {
    return ((y > -1 && y < h) && (x > -1 && x < w));
}