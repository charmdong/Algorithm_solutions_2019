/**
 * @author : donggun.chung
 * @date : 2020.02.16
 * @site : BOJ
 * @prob_Info : 2636 치즈 
 * @time : 0ms
 * @memory : 2120KB
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, total;
vector<vector<int>> board;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int solution();
vector<pair<int, int>> findPart(int y = 0, int x = 0);
bool removePart(vector<pair<int, int>> part);

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> R >> C;

    board.assign(R, vector<int>(C, 0));

    for(int row = 0; row < R; row++) {
        for(int col = 0; col < C; col++) {
            cin >> board[row][col];

            if(board[row][col] == 1) {
                total++;
            }
        }
    }

    cout << solution() << endl;
    cout << total << endl;

    return 0;
}

int solution() {
    int answer = 0;

    while(true) {
        answer++;
        if(removePart(findPart())) {
            break;
        }
    }

    return answer;
}

vector<pair<int, int>> findPart(int y, int x) {
    vector<pair<int, int>> part;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    visited[y][x] = true;
    q.push({y, x});
    
    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int ny = now.first + dy[dir];
            int nx = now.second + dx[dir];

            if(ny > -1 && ny < R && nx > -1 && nx < C) {
                if(!visited[ny][nx]) {
                    visited[ny][nx] = true;
                    if(board[ny][nx] == 0) {
                        q.push({ny, nx});
                    } else{
                        part.push_back({ny, nx});
                    }
                }
            }
        }
    }

    return part;
}

bool removePart(vector<pair<int, int>> part) {
    int cnt = part.size();

    for(pair<int, int> p : part) {
        board[p.first][p.second] = 0;
    }

    if(total - cnt > 0) {
        total -= cnt;
        return false;
    } else {
        return true;
    }
}