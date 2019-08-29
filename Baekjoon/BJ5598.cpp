#include <iostream>
#include <string>
using namespace std;

string solution(string str); // decode Caesar string

int main()
{
    string str;
    cin >> str;
    cout << solution(str);

    return 0;
}

string solution(string str) {
    string answer = "";
    int len = str.length();

    for(int i=0; i<len; i++) {
        int diff = str[i] - 3;

        if(diff < 65) {
            answer += diff + 26;
        } else {
            answer += diff;
        }
    }

    return answer;
}