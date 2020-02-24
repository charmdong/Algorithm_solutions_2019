#include <iostream>

using namespace std;

int E; // 1 ~ 15
int S; // 1 ~ 28
int M; // 1 ~ 19

int solution();

int main()
{
    cin >> E >> S >> M;

    cout << solution() << endl;

    return 0;
}

int solution() {
    int answer = 1;
    int earth = 1, sun = 1, moon = 1;
    // TODO: 코드 최적화
    while(true) {
        if (earth == E && sun == S && moon == M) {
            break;
        }

        earth++;
        if(earth > 15) {
            earth = 1;
        }

        sun++;
        if(sun > 28) {
            sun = 1;
        }

        moon++;
        if(moon > 19) {
            moon = 1;
        }

        answer++;
    }

    return answer;
}