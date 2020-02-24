/**
 * @author : donggun.chung
 * @date : 2020.02.15
 * @site : BOJ
 * @prob_Info : 16948 데스 나이트 
 * @time : 0ms
 * @memory : 2248KB
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, srcY, srcX, desY, desX;
int dy[6] = {-2, -2, 0, 0, 2, 2};
int dx[6] = {-1, 1, -2, 2, -1, 1};
vector<vector<int>> board;

int solution();

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    board.assign(N, vector<int>(N, 0));

    cin >> srcY >> srcX >> desY >> desX;

    cout << solution() << endl;

    return 0;
}

int solution() {
    queue<pair<int, int>> q;

    q.push({srcY, srcX});

    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        if(now == make_pair(desY, desX)) {
            return board[desY][desX];
        }

        for(int dir = 0; dir < 6; dir++) {
            int ny = now.first + dy[dir];
            int nx = now.second + dx[dir];

            if(ny > -1 && ny < N && nx > - 1 && nx < N) {
                if(board[ny][nx] == 0) {
                    q.push({ny, nx});
                    board[ny][nx] = board[now.first][now.second] + 1;
                }
            }
        }
    }

    return -1;
}