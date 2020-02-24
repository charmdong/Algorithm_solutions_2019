/**
 * @author : donggun.chung
 * @date : 2020.02.09
 * @site : BOJ
 * @prob_Info : 2567 색종이-2 
 * @time : 0ms
 * @memory : 2024KB
 */

#include <iostream>

using namespace std;

int board[100][100];
int dy[4] = {-1 ,0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int solution();
bool isInBoard(int y, int x);

int main()
{
    int n;
    int y, x;

    cin >> n;

    for(int index = 0; index < n; index++) {
        cin >> y >> x;

        for(int row = y; row < y + 10; row++) {
            for(int col = x; col < x + 10; col++) {
                if(board[row][col] == 0) {
                    board[row][col] = 1;
                }
            }
        }
    }

    cout << solution() << endl;

    return 0;
}

int solution() {
    int answer = 0;

    for(int row = 0; row < 100; row++) {
        for(int col = 0; col < 100; col++) {
            if(board[row][col] == 1) {
                for(int dir = 0; dir < 4; dir++) {
                    int y = row + dy[dir];
                    int x = col + dx[dir];

                    if((isInBoard(y, x) && board[y][x] == 0) || !isInBoard(y, x)) {
                        answer++;
                    }
                }
            }
        }
    }

    return answer;
}

bool isInBoard(int y, int x) {
    return ((y > -1 && y < 100) && (x > -1 && x < 100));
}