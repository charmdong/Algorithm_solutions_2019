/**
 * @author : donggun.chung
 * @date : 2020.02.09
 * @site : BOJ
 * @prob_Info : 9613 GCD 합 
 * @time : 0ms
 * @memory : 1984KB
 */

#include <iostream>
#include <vector>

using namespace std;

int TC, N;
vector<int> list;

long long solution();
int gcd(int n, int m);

int main()
{
    cin >> TC;

    for(int test = 0; test < TC; test++) {
        cin >> N;
        list.assign(N, 0);

        for(int index = 0; index < N; index++) {
            cin >> list[index];
        }

        cout << solution() << endl;
    }

    return 0;
}

long long solution() {
    long long answer = 0;

    for(int first = 0; first < N - 1; first++) {
        for(int second = first + 1; second < N; second++) {
            answer += gcd(list[first], list[second]);
        }
    }

    return answer;
}

int gcd(int n, int m) {
    return (m > 0) ? gcd(m, n%m) : n;
}