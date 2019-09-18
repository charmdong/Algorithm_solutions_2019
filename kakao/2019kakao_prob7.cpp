#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool visited[101][101];
int res[101][101];

int solution(vector<vector<int>> board) {
    int answer = 0;
    int size = board.size();
    struct Robot {
        pair<int, int> p1;
        pair<int, int> p2;

        Robot() {}
        Robot(pair<int, int> p1, pair<int, int> p2) : p1(p1), p2(p2) {}
    };
    Robot r;
    r.p1 = {1,1};
    r.p2 = {1,2};

    queue<Robot> q;
    q.push(r);
    visited[r.p1.first][r.p1.second] = visited[r.p2.first][r.p2.second] = true;

    while(!q.empty()) {
        Robot now = q.front();
        q.pop();

        if(now.p1 == make_pair(size, size) || now.p2 == make_pair(size, size)) {
            return res[size][size];
        }

        for(int dir=0; dir<4; dir++) {
            pair<int, int> np1 = {now.p1.first + dy[dir], now.p1.second + dx[dir]};
            pair<int, int> np2 = {now.p2.first + dy[dir], now.p2.second + dx[dir]};

            if(isInBoard(np1.first, np1.second, size) && isInBoard(np2.first, np2.second, size)) {
                if(board[np1.first][np1.second] == 0 && board[np2.first][np2.second] == 0) {
                    if(!visited[np1.first][np1.second] || !visited[np2.first][np2.second]) {
                        visited[np1.first][np1.second] = visited[np2.first][np2.second] = true;
                        q.push(Robot(np1, np2));
                    }
                }
            }
            // 회전하는 경우
        }
    }


    return answer;
}

bool isInBoard(int y, int x, int n) {
    if( y > 0 && y <= n) {
        if(x > 0 && x <= n) {
            return true;
        }
    }

    return false;
}