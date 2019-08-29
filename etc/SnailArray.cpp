#include <iostream>
using namespace std;

void snail(int **, int, int);
void print(int **, int, int);

int main()
{
		int col, row;
		int **ary;
		cout << "input col and row : ";
		cin >> col >> row;
		
		ary = new int*[col];
		for (int i = 0; i < col; i++) {
				ary[i] = new int[row];
		}

		snail(ary,col,row);

		for (int i = 0; i < col; i++) {
				delete[] ary[i];
		}
		delete[] ary;

		return 0;
}

void snail(int **ary, int col, int row) {
		int total = col * row;
		int rC = col-1, rR = row;
		int cnt = 1;
		int x = 0,y = -1;
		int turn=1;

		while (cnt <= total) {
				for (int i = 0; i < rR; i++) {
						y += turn;
						ary[x][y] = cnt++;
				}
				if (cnt >= total) break;
				rR--;
				
				for (int i = 0; i < rC; i++) {
						x += turn;
						ary[x][y] = cnt++;
				}
				rC--;
				turn *= -1;
		}

		print(ary, col, row);
}

void print(int **ary, int col, int row) {
		for (int i = 0; i < col; i++) {
				for (int j = 0; j < row; j++) {
						cout << ary[i][j] << "\t";
				}
				cout << endl;
		}
}