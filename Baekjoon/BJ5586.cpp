#include <iostream>
#include <string>
#include <vector>
using namespace std;

pair<int, int> solution(string str);

int main()
{
    pair<int, int> res;
    string str;

    cin >> str;
    res = solution(str);
    cout << res.first << "\n" << res.second;
    
    return 0;
}

pair<int, int> solution(string str)
{
    pair<int, int> answer({0, 0});
    const string JOI = "JOI";
    const string IOI = "IOI";
    int len = str.length();

    for (int i = 0; i < len - 2; i++)
    {
        string valid = str.substr(i, 3);
        if(valid == JOI) {
            answer.first++;
        }

        if(valid == IOI) {
            answer.second++;
        }
    }

    return answer;
}