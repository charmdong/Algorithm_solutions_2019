/**
 * 팰린드롬 만들기
 */ 

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool isPanlin(vector<char>);
string solution(string name);

int main()
{
    string name;

    cin >> name;
    cout << solution(name) << endl;
    
    return 0;
}

string solution(string name) {
    string answer = "I'm Sorry Hansoo";
    vector<char> cList;

    for(int index = 0; index < name.length(); index++) {
        cList.push_back(name[index]);
    }
    
    while(true) {
        if(isPanlin(cList)) {
            answer = "";
            for(char c : cList) {
                answer += c;
            }
            break;
        }

        if(!next_permutation(cList.begin(), cList.end())) {
            break;
        }
    }

    return answer;
}

bool isPanlin(vector<char> cList) {
    bool isPan = true;

    for(int index = 0; index < cList.size() / 2; index++) {
        if(cList[index] != cList[cList.size() - index - 1]) {
            isPan = false;
            break;
        }
    }

    return isPan;
}