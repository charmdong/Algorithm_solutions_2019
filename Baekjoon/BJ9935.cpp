#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string solution(string origin, string bomb);

int main()
{
    string origin, bomb;
    cin >> origin;
    cin >> bomb;
    cout << solution(origin, bomb) << endl;

    return 0;
}
// FIXME: 시간 초과
string solution(string origin, string bomb) {
    int bombLen = bomb.length();
    int index;

    while((index = origin.find(bomb, 0)) != -1) {
        origin.replace(index, bombLen, "");
    }

    if(origin == "") {
        return "FRULA";
    }
    return origin;
}