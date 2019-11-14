/**
 * PG : stick
 */ 

#include <string>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int stack = 0;

    for(int index = 0; index < arrangement.length(); index++) {
        if(arrangement[index] == '(') {
            stack++;
        } else {
            if(arrangement[index - 1] == '(') {
                answer += (--stack);
            } else {
                answer++;
                stack--;
            }
        }
    }

    return answer;
}

int main()
{
    string str = "wer";

    str.c_str();
}