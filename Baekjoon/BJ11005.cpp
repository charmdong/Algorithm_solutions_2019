#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string solution(int n, int b);

int main()
{
    int n, b;
    
    cin >> n >> b;
    cout << solution(n, b) << endl;

    return 0;
}

string solution (int n, int b) {
    string answer = "";
    int share = 0;
    int remain = 0;

    while (n) {
        share = n / b;
        remain = n % b;

        if (remain < 10) {
            answer = to_string(remain) + answer;
        } else {
            char ch = remain + 55;
            answer = ch + answer;
        }

        n /= b;
    }

    return answer;
}