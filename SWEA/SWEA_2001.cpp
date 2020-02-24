/**
 * @author : donggun.chung
 * @date : 2020.02.11
 * @site : SWEA
 * @prob_Info : 2001 파리 퇴치 
 * @time : 6ms
 * @memory : 12MB
 */

#include <iostream>
#define MAX 15

using namespace std;

int TC, N, M;
int board[MAX][MAX];

int solution();

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> TC;

    for(int test = 1; test <= TC; test++) {
        cin >> N >> M;

        for(int row = 0; row < N; row++) {
            for(int col = 0; col < N; col++) {
                cin >> board[row][col];
            }
        }

        cout << "#" << test << " " << solution() << endl;
    }

    return 0;
}

int solution() {
    int answer = 0;

    for(int row = 0; row <= N - M; row++) {
        for(int col = 0; col <= N - M; col++) {
            int total = 0;

            for(int r = row; r < row + M; r++) {
                for(int c = col; c < col + M; c++) {
                    total += board[r][c];
                }
            }

            if(answer < total)
                answer = total;
        }
    }

    return answer;
}