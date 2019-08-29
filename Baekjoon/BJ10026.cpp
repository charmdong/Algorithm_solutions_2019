#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

int n;
int dx[4] = { -1, 0 ,1 , 0 };
int dy[4] = { 0,-1,0,1 };
char board[MAX][MAX];
int visited[MAX][MAX];

bool isInBoard(int x, int y);
void bfs(int y, int x);

int main()
{
	int part = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	
	// CASE 1: Normal Person
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				part++;
			}
		}
	}

	cout << part << " ";
	part = 0;

	// Init the visited array & board to abnormal case
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
			if (board[i][j] == 'R')
				board[i][j] = 'G';
		}
	}

	// CASE 2: Abnormal Person
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				part++;
			}
		}
	}

	cout << part << endl;

	return 0;
}

void bfs(int y, int x) {
	queue<pair<int, int >> q;
	char col = board[y][x];

	q.push(make_pair(y, x));
	visited[y][x] = 1;

	while (!q.empty()) {
		pair<int, int > now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (isInBoard(ny, nx) && board[ny][nx] == col && !visited[ny][nx]) {
				visited[ny][nx] = 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

bool isInBoard(int x, int y) {
	if (x >= 0 && x < n)
		if (y >= 0 && y < n)
			return true;
	return false;
}