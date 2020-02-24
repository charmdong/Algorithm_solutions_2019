/**
 * @author : donggun.chung
 * @date : 2020.02.14
 * @site : 
 * @prob_Info : 
 * @time : 
 * @memory : 
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[3] = {0, -1, 1};
int dx[3] = {1, 1, 1};

int R, C;
vector<vector<char>> board;
vector<vector<bool>> visited;
vector<vector<int>> res;

int solution();
bool isInBoard(int y, int x);

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> R >> C;

    board.assign(R, vector<char>(C, 0));
    visited.assign(R, vector<bool>(C, false));

    for(int row = 0; row < R; row++) {
        for(int col = 0; col < C; col++) {
            cin >> board[row][col];
        }
    }

    cout << solution() << endl;

    return 0;
}

int solution() {
    int answer = 0;

    for (int row = 0; row < R; row++)
    {
        answer = 0;
        queue<pair<int, int>> q;

        q.push({row, 0});
        visited[row][0] = true;

        while (!q.empty())
        {
            pair<int, int> now = q.front();
            q.pop();

            for (int dir = 0; dir < 3; dir++)
            {
                int ny = now.first + dy[dir];
                int nx = now.second + dx[dir];

                if (isInBoard(ny, nx) && board[ny][nx] != 'x')
                {
                    if (!visited[ny][nx])
                    {
                        visited[ny][nx] = true;
                        res[ny][nx] = res[now.first][now.second] + 1;
                        q.push({ny, nx});
                    }
                }
            }
        }

        if(answer < res[row][C - 1]) {
            answer = res[row][C - 1];
        }
    }

    return answer;
}

bool isInBoard(int y, int x) {
    return (y > -1 && y < R && x > -1 && x < C);
}