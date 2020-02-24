/**
 * @author : donggun.chung
 * @date : 2020.02.09
 * @site : BOJ
 * @prob_Info : 1120 문자열 
 * @time : 0ms
 * @memory : 1984KB
 */

#include <iostream>
#include <string>

using namespace std;

int solution(string origin, string str);

int main()
{
    string str, origin;

    cin >> str >> origin;

    cout << solution(origin, str) << endl;

    return 0;
}

int solution(string origin, string str) {
    int answer = origin.length();
    int len = str.length();
    int diffLen = origin.length() - len;

    for(int start = 0; start <= diffLen; start++) {
        int diff = 0;

        for(int index = start; index < start + len; index++) {
            if(origin[index] != str[index - start]) {
                diff++;
            }
        }

        if(diff < answer) {
            answer = diff;
        }
    }

    return answer;
}