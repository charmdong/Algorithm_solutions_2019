/**
 * @author : donggun.chung
 * @date : 2020.02.07
 * @site : BOJ
 * @prob_Info : 2979 트럭 주차 
 * @time : 0ms
 * @memory : 1984KB
 */

#include <iostream>
#define ARRIVE 0
#define LEAVE 1
using namespace std;

int A, B, C;
int truck[3][2];
int parking[101];

int solution();

int main()
{
    cin >> A >> B >> C;

    for(int index = 0; index < 3; index++) {
        cin >> truck[index][ARRIVE];
        cin >> truck[index][LEAVE];
    }

    cout << solution() << endl;

    return 0;
}

int solution() {
    int answer = 0;

    for(int index = 0; index < 3; index++) {
        for(int time = truck[index][ARRIVE]; time < truck[index][LEAVE]; time++) {
            parking[time]++;
        }
    }

    for(int time = 1; time <= 100; time++) {
        int truckCnt = parking[time];

        if(truckCnt == 1) {
            answer += A;
        } else if(truckCnt == 2) {
            answer += 2*B;
        } else if(truckCnt == 3) {
            answer += 3*C;
        } else {
            continue;
        }
    }

    return answer;
}