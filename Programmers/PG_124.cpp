#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    while(n > 0) {
        int remain = n % 3;

        if(remain == 0) {
            answer += "4";
            n = n/3 - 1;
        }
        else {
            answer += to_string(remain);
            n /= 3;
        }
    }

    for(int index = 0; index < answer.length() / 2; index++) {
        char tmp = answer[index];
        answer[index] = answer[answer.length() - index - 1];
        answer[answer.length() - index - 1] = tmp;
    }

    return answer;
}