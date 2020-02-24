/**
 * @author : donggun.chung
 * @date : 2020.02.24
 * @site : BOJ
 * @prob_Info : 18405 경쟁적 전염 
 * @time : 4ms
 * @memory : 2556KB
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, S, Y, X;
vector<vector<int>> board, time;
vector<vector<bool>> visited;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void bfs();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	board.assign(N + 1, vector<int>(N + 1, 0));
	time.assign(N + 1, vector<int>(N + 1, 0));
	visited.assign(N + 1, vector<bool>(N + 1, false));

	for (int row = 1; row <= N; row++) {
		for (int col = 1; col <= N; col++) {
			cin >> board[row][col];

			if (board[row][col] > 0) {
				q.push(make_pair(board[row][col], make_pair(row, col)));
			}
		}
	}

	cin >> S >> Y >> X;

	bfs();

	return 0;
}

void bfs() {
    if(S == 0) {
        cout << board[Y][X] << endl;
        return;
    }

	queue<pair<int, int>> que;

	while (!q.empty()) {
		auto now = q.top();
        
		que.push(now.second);
		visited[now.second.first][now.second.second] = true;

		q.pop();
	}

	while (!que.empty()) {
		pair<int, int> now = que.front();
		que.pop();

		if (time[now.first][now.second] == S) {
            cout << board[Y][X] << endl;
			return;
		}

		for (int dir = 0; dir < 4; dir++) {
			int ny = now.first + dy[dir];
			int nx = now.second + dx[dir];

			if (ny > 0 && ny <= N && nx > 0 && nx <= N) {
				if (board[ny][nx] == 0 && !visited[ny][nx]) {
					visited[ny][nx] = true;
					board[ny][nx] = board[now.first][now.second];
					time[ny][nx] = time[now.first][now.second] + 1;
					que.push({ ny, nx });
				}
			}
		}
	}
    
    cout << board[Y][X] << endl;
}