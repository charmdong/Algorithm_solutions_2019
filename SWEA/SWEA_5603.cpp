/**
 * @author : donggun.chung
 * @date : 2020.02.11
 * @site : SWEA
 * @prob_Info : 
 * @time : 
 * @memory : 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC, N;
vector<int> dump;

int solution();

int main()
{
    cin >> TC;

    for(int test = 1; test <= TC; test++) {
        cin >> N;
        dump.assign(N, 0);
        
        for(int index = 0; index < N; index++) {
            cin >> dump[index];
        }
        
        sort(dump.begin(), dump.end());
        cout << "#" << test << " " << solution() << endl;
    }

    return 0;
}

int solution() {
    int answer = 0;
    int total = 0;

    for(int t : dump) {
        total += t;
    }

    int avg = total / N;

    for(int t : dump) {
        if(t > avg) {
            break;
        }

        answer += (avg - t);
    }

    return answer;
}