/**
 * @author : donggun.chung
 * @date : 2020.02.09
 * @site : BOJ
 * @prob_Info : 2563 색종이
 * @time : 0ms
 * @memory : 2024KB
 */

#include <iostream>

using namespace std;

int board[100][100];

int solution();

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
                answer++;
            }
        }
    }

    return answer;
}