/// 경로 찾기

#include <iostream>
#include <queue>
using namespace std;

int n;
int board[100][100];

void solution();

int main()
{
	solution();
	return 0;
}

void solution() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][k] && board[k][j])
					board[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
}