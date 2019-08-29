///알고리즘 문제해결전략 6-5 : 게임판 덮기

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool set(vector<vector<int>>& board, int y, int x, int type, int delta);
int cover(vector<vector<int>>&board);
void printBoard(vector<vector<int>> );

const int coverType[4][3][2] = {
		{ { 0,0 },{ 1,0 },{ 0,1 } },
		{ { 0,0 },{ 0,1 },{ 1,1 } } ,
		{ { 0,0 },{ 1,0 },{ 1,1 } },
		{ { 0,0 },{ 1,0 },{ 1,-1 } }
};

int main()
{
		int testCnt;
		int height, width;

		cin >> testCnt;
		while (testCnt--) {
				cin >> height >> width;
				vector<vector<int>> board;
				string line;
				for (int i = 0; i <height; i++) {
						board.push_back(vector<int>(width, 0));
						cin >> line;
						for (int k = 0; k < line.size(); k++)
								if (line[k] == '#')
										board[i][k] = 1;
				}
				//printBoard(board);
				cout << cover(board) << endl;
		}

		return 0;
}

bool set(vector<vector<int>>& board, int y, int x, int type, int delta) {
		bool ok = true;
		for (int i = 0; i < 3; i++) {
				const int ny = y + coverType[type][i][0];
				const int nx = x + coverType[type][i][1];
				if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
						ok = false;
				else if ((board[ny][nx] += delta) > 1)
						ok = false;
		}
		return ok;
}

int cover(vector<vector<int>>&board) {
		//cout << "TEST\n";
		int y = -1, x = -1;
		for (int i = 0; i < board.size(); i++) {
				for (int k = 0; k<board[i].size(); k++) {
						if (board[i][k] == 0) {
								y = i;
								x = k;
								break;
						}
				}
				if (y != -1)
						break;
		}

		if (y == -1) return 1;
		int ret = 0;

		for (int type = 0; type < 4; type++) {
				if (set(board, y, x, type, 1))
						ret += cover(board);
				set(board, y, x, type, -1);
		}
		return ret;
}

void printBoard(vector<vector<int>> board) {
		for (int i = 0; i < board.size(); i++) {
				for (int k = 0; k < board[i].size(); k++)
						cout << board[i][k] << " ";
				cout << endl;
		}
}