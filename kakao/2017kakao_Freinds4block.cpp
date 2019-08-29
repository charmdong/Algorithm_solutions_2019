/// 2017 kakao blind coding test : Freinds 4 block

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<string> board);

int main()
{
	int m, n;
	cin >> m >> n;
	//cout << solution(m, n, { "TTTANT","RRFACC","RRRFCC","TRRRAA","TTMMMF","TMMTTJ" }) << endl;
	cout << solution(m, n, { "CCBDE","AAADE","AAABF","CCBBF" });
	return 0;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0, check = 0;// 지워지는 블록의 수
	vector<int> row(n, 0);
	vector<vector<int>> table(m, row);
	
	
	// 지울 수 있는 블록 위치 찾기
	for (int i = 0; i < m-1; i++) {
		for (int k = 0; k < n-1; k++) {
			if (board[i][k] == '\0') continue;
			if (board[i][k] == board[i][k + 1] && board[i][k + 1] == board[i + 1][k] && board[i + 1][k] == board[i + 1][k + 1]){
				table[i][k]++;
				table[i][k + 1]++;
				table[i + 1][k]++;
				table[i + 1][k + 1]++;
			}
		}
	}
	// 사라진 블록 개수 세기
	for (int i = 0; i < m; i++) {
		for (int k = 0; k< n; k++) {
			if (table[i][k] >= 1) {
				answer++;
				board[i][k] = '\0';
			}
		}
	}
	if (answer == 0) return answer;
	
	// 블록 밀기
	while (1) {
		for (int i = 0; i < m - 1; i++) {
			for (int k = 0; k < n; k++) {
				if (board[i][k] !='\0' && board[i + 1][k] == '\0') {
					board[i + 1][k] = board[i][k];
					board[i][k] = '\0';
					check = 1;
				}
			}
		}
		if (check == 0) break;
		check = 0;
	}

	return answer + solution(m,n,board);
}