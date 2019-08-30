#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution (string str1, string str2);

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    cout << solution(str1, str2) << endl;

    return 0;
}

int solution (string str1, string str2) {
    int answer = 0;
    int count[2][26] = {0};

    for(int i=0; i<str1.length(); i++) {
        count[0][str1[i]-97]++;
    }

    for(int i=0; i<str2.length(); i++) {
        count[1][str2[i]-97]++;
    }

    for(int i=0; i<26; i++) {
        if(count[0][i] != count[1][i]) {
            answer += abs(count[0][i] - count[1][i]);
        }
    }

    return answer;
}