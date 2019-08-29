#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string str);

int main()
{
    string str;
    cin >> str;
    cout << solution(str) << endl;
    return 0;
}

string solution(string str)
{
    string answer = "";
    vector<char> validation = {'C', 'A', 'M', 'B', 'R', 'I', 'D', 'G', 'E'};
    int len = str.length();

    sort(validation.begin(), validation.end());
    for(int i=0; i<len; i++) {
        if(!binary_search(validation.begin(), validation.end(), str[i])) {
            answer += str[i];
        }
    }

    return answer;
}