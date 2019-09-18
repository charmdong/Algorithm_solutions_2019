#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s);

int main()
{
    //cout << solution("aabbaccc") << endl;
    //cout << solution("ababcdcdababcdcd") << endl;
    //cout << solution("abcabcdede") << endl;
    //cout << solution("abcabcabcabcdededededede") << endl;
    cout << solution("xababcdcdababcdcd");
    return 0;
}

int solution(string str)
{
    int answer = 1001;
    int len = str.length();

    for(int word = 1; word <= len; word++) {
        vector<string> subStrList;
        
        for(int index = 0; index < len; index+= word) {
            string subStr = str.substr(index, word);
            subStrList.push_back(subStr);
        }

        int listLen = subStrList.size();
        int count = 1;
        string checkStr = subStrList[0];
        string res = "";

        for(int index = 1; index < listLen; index++) {
            if(checkStr == subStrList[index]) {
                count++;
            } else {
                if(count != 1) {
                    res += to_string(count);
                } 
                res += checkStr;
                count = 1;
                checkStr = subStrList[index];
            }
        }
        if(count != 1) {
            res += to_string(count);
        }
        res += checkStr;
        answer = (answer > res.length()) ? res.length() : answer;
    }

    return answer;
}