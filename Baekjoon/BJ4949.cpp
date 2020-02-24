#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solution(string str);

int main()
{
    string str;

    while(true) {
        getline(cin, str);
        if (str == ".") {
            break;
        }
        
        cout << solution(str) << endl;
    }

    return 0;
}

string solution(string str) {
    bool isGood = true;
    stack<char> s;
    int len = str.length();

    for(int index = 0; index < len; index++) {
        char ch = str[index];

        if(ch == '(' || ch == '[') {
            s.push(ch);
        } else if(ch ==')' || ch ==']') {
            if(s.empty()) { // CASE: stack is empty
                isGood = false;
                break;
            }

            if((ch == ')' && s.top() == '(') || (ch == ']' && s.top() == '[')) {
                s.pop();
            } else {
                isGood = false;
                break;
            }
        } else {
            continue;
        }
    }

    if(!s.empty()) {
        isGood = false;
    }

    return isGood ? "yes" : "no";    
}