#include <iostream>
#include <string>
#include <vector>
#define BAD 0
#define VALANCE 1
#define CORRECT 2
using namespace std;

string solution(string str);
int check(string str);

int main()
{
    cout << solution("()))((()())(") << endl;
    return 0;
}

string solution(string str) {
    string answer = "";

    if(str.length() == 0 || check(str) == CORRECT) {
        return str;
    }
    
    int strLen = str.length();
    int checkRes;
    string u = "";
    string v = "";

    for(int wordCnt = 2; wordCnt <= strLen; wordCnt += 2) {
        string subStr = str.substr(0, wordCnt);
        checkRes = check(subStr);

        if(checkRes != BAD) {
            u = subStr;
            v = str.substr(wordCnt);
            break;
        }
    }

    if(checkRes == CORRECT) {
        return u + solution(v);
    }
    else {
        answer += "(";
        answer += solution(v);
        answer += ")";

        int uLen = u.length();
        for(int index = 1; index < uLen - 1; index++) {
            answer += (u[index] == '(') ? ")" : "(";
        }

        return answer;
    }
}

int check(string str)
{
    vector<char> stack;
    int openCount = 0;
    int closeCount = 0;
    int strLen = str.length();
    bool isCorrect = true;
 
    for(int index = 0; index < strLen; index++) {
        char ch = str[index];
        
        if(ch == '(') {
            stack.push_back(ch);
            openCount++;
        } else {
            if(stack.empty()) {
                isCorrect = false;
                closeCount++;
                continue;
            }

            if(stack[stack.size() - 1] == '(') {
                stack.pop_back();
            }
            closeCount++;
        }
    }

    if(isCorrect && (openCount == closeCount)) {
        return CORRECT;
    } else if(openCount == closeCount) {
        return VALANCE;
    } else {
        return BAD;
    }
}