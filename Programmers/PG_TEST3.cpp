#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> signs);

int main()
{
	auto t = solution(3, { {0, 1, 0},{0, 0, 1},{1, 0, 0} });
	return 0;
}

vector<vector<int>> solution(int n, vector<vector<int>> board){
	vector<vector<int>> res;
	
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][k] && board[k][j])
					board[i][j] = 1;
			}
		}
	}
	
	res = board;
	return res;
}