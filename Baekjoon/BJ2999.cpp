/**
 * @author : donggun.chung
 * @date : 2020.02.06
 * @site : BOJ 
 * @prob_Info : 2999 비밀 이메일 
 * @time : 0ms
 * @memory : 1988kb 
 */

#include <iostream>
#include <string>

using namespace std;

void solution(string str);

int main()
{
    string str;
    cin >> str;
    solution(str);
    return 0;
}

void solution(string str) {
    int len = str.length();
    int row = 0, col = 0;

    for(int num = 1; num <= len / 2; num++) {
        if(len % num == 0) {
            int tmpR = num;
            int tmpC = len / num;

            if(tmpR <= tmpC) {
                if(row < tmpR) {
                    row = tmpR;
                    col = tmpC;
                }
            }
        }
    }

    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            cout << str[c * row + r];
        }
    }
}