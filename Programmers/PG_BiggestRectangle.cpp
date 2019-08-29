/// 가장 큰 정사각형

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board);

int main()
{
	cout << solution({ {0,1,1,1},{1,1,1,1}, {1,1,1,1}, {0,0,1,0} });
	return 0;
}

int solution(vector<vector<int>> board) {
	int max = 0;

	for (int i = 0; i < board.size()-1; i++) {
		for (int k = 0; k < board[i].size()-1; k++) {
			if (board[i][k] != 0) {
				if (board[i + 1][k] != 0 && board[i][k + 1] != 0 && board[i + 1][k + 1] != 0)
					board[i + 1][k + 1] += min(board[i][k],min(board[i + 1][k],  board[i][k+1]));
			}
		}
	}

	for (int i = 0; i < board.size(); i++) {
		int tmp = *max_element(board[i].begin(), board[i].end());
		if (max < tmp)
			max = tmp;
	}

	return max * max;
}