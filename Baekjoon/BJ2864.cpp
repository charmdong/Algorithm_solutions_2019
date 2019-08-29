#include <iostream>
#include <string>
using namespace std;

pair<int, int> solution(int, int);

int main()
{
    int num1, num2;
    cin >> num1 >> num2;

    pair<int, int> res = solution(num1, num2);
    cout << res.first << " " << res.second;

    return 0;
}

pair<int, int> solution(int num1, int num2) {
    pair<int, int> answer;
    string str1 = to_string(num1);
    string str2 = to_string(num2);
    int strLen1 = str1.length();
    int strLen2 = str2.length();

    string min1 = str1;
    string min2 = str2;

    for(int i=0; i<strLen1; i++) {
        if(min1[i] == '6') {
            min1[i] = '5';
        }
    }

    for(int i=0; i<strLen2; i++) {
        if(min2[i] == '6') {
            min2[i] = '5';
        }
    }

    answer.first = atoi(min1.c_str()) + atoi(min2.c_str());

    string max1 = str1;
    string max2 = str2;

    for(int i=0; i<strLen1; i++) {
        if(max1[i] == '5') {
            max1[i] = '6';
        }
    }

    for(int i=0; i<strLen2; i++) {
        if(max2[i] == '5') {
            max2[i] = '6';
        }
    } 

    answer.second = atoi(max1.c_str()) + atoi(max2.c_str());

    return answer;
}