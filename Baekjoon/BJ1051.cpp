/**
 * BJ : 숫자 정사각형
 */ 

#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int row, int col);

int main()
{
    int n, m;
    vector<vector<int>> board;

    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            scanf("%1d", &board[row][col]);
        }
    }

    cout << solution(board, n, m) << endl;

    return 0;
}

int solution(vector<vector<int>> board, int n, int m) {
    int answer = 1;
    int limit = (n < m) ? n : m;

    for(int row = 0; row < n - 1; row++) {
        for(int col = 0; col < m - 1; col++) {
            for(int len = 1; len < limit; len++) {
                if(row + len >= n || col + len >= m) {
                    continue;
                }

                int now = board[row][col];

                if (board[row + len][col] == now &&
                    board[row][col + len] == now &&
                    board[row + len][col + len] == now)
                {
                    int area = (len + 1) * (len + 1);
                    answer = (answer < area) ? area : answer;
                }
            }
        }
    }

    return answer;
}