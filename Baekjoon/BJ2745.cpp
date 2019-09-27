#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int solution(string n, int b);

int main()
{
    string n;
    int b;

    cin >> n >> b;
    cout << solution(n, b) << endl;

    return 0;
}

int solution (string n, int b) {
    int answer = 0;
    int len = n.length();

    for(int index = 0; index < len; index++) {
        if (n[index] >= 'A' && n[index] <= 'Z') {
            int tmpNum = n[index] - 55;
            
            answer += (tmpNum * pow(b, len - index - 1));
        } else {
            answer += ((n[index] - '0') * pow(b, len - index - 1));
        }
    }

    return answer;
}