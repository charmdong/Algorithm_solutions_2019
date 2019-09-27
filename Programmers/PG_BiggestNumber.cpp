/**
 * PG : 가장 큰 수
 */ 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string &a, string &b) {
    return (a + b) > (b + a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numString;

    for(int n : numbers) {
        numString.push_back(to_string(n));
    }

    sort(numString.begin(), numString.end(), cmp);

    for(string str : numString) {
        answer += str;
    }

    if(answer[0] == '0') {
        return "0";
    }
    
    return answer;
}