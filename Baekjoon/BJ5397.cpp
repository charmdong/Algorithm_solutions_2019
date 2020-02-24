#include <iostream>
#include <string>
#include <list>

using namespace std;

int TC;

string solution(string str);

int main()
{
    string str;
    cin >> TC;

    for(int test = 0; test < TC; test++) {
        cin >> str;
        cout << solution(str) << endl;
    }

    return 0;
}

string solution(string str) {
    string answer = "";
    list<char> cList;
    
    auto iter = cList.begin();
    int len = str.length();

    for(int index = 0; index < len; index++) {
        char ch = str[index];

        switch (ch) {
        case '<':
            if(iter != cList.begin()) iter--;
            break;
        case '>':
            if(iter != cList.end()) iter++;
            break;
        case '-':
            if(iter != cList.begin()) {
                iter = cList.erase(--iter);
            }
            break;
        default:
            cList.insert(iter, ch);
            break;
        }
    }

    for(char ch : cList) {
        answer += ch;
    }

    return answer;
}