#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> solution();

int main()
{
    vector<char> res = solution();
    for(char ch : res) {
        cout << ch;
    }
    return 0;
}

vector<char> solution() {
    vector<char> answer;
    vector<int> count(0, 26);
    string str;

    while(!cin.eof()) { // FIXME: 입력 받는 방식
        cin >> str;
        int len = str.length();
        for(int i=0; i<len; i++) {
            count[str[i] - 97]++;
        }
    }

    int max = *max_element(count.begin(), count.end());
    for(int i=0; i<26; i++) {
        if(count[i] == max) {
            answer.push_back(i + 97);
        }
    }

    return answer;
}