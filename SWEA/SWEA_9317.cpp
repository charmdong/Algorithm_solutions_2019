#include <iostream>
#include <string>

using namespace std;

int TC, N;
int solution(string, string);

int main()
{
    string origin;
    string seok;

    cin >> TC;

    for(int test = 1; test <= TC; test++) {
        cin >> N;
        cin >> origin >> seok;

        cout << "#" << test << " " << solution(origin, seok) << endl;
    }

    return 0;
}

int solution(string origin, string seok) {
    int answer = 0;

    for(int index = 0; index < N; index++) {
        if(origin[index] == seok[index]) {
            answer++;
        }
    }

    return answer;
}