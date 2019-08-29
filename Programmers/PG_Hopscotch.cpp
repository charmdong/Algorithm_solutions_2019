/// 땅따먹기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board);

int main()
{
	cout << solution({ {1,2,3,5},{5,6,7,8},{4,3,2,1} });
	return 0;
}

int solution(vector<vector<int>> board) {
	int len = board.size();

	for (int i = 0; i < len - 1; i++) {
		board[i + 1][0] += max(board[i][1], max(board[i][2], board[i][3]));
		board[i + 1][1] += max(board[i][0], max(board[i][2], board[i][3]));
		board[i + 1][2] += max(board[i][1], max(board[i][0], board[i][3]));
		board[i + 1][3] += max(board[i][1], max(board[i][2], board[i][0]));
	}
	// 아래줄 누적 값 : 이전 행의 다른 열들 중에서 가장 큰 값을 더해줌.

	return *max_element(board[len - 1].begin(), board[len - 1].end());
}