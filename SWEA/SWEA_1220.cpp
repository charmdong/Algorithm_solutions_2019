/**
 * @author : donggun.chung
 * @date : 2020.02.11
 * @site : SWEA
 * @prob_Info : 1220 Magnetic 
 * @time : 17ms
 * @memory : 12MB
 */

#include <iostream>

using namespace std;

int N;
int board[100][100];

int solution();

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int test = 1; test <= 10; test++) {
        cin >> N;

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

    for(int col = 0; col < N; col++) {
        bool lock = false;

        for(int row = 0; row < N; row++) {
            if(lock && board[row][col] == 2) {
                answer++;
                lock = false;
                continue;
            }

            if(!lock && board[row][col] == 1) {
                lock = true;
            }
        }
    }

    return answer;
}