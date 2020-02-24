#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<string> board);
bool isGood(vector<string> board, int start, int limit);

int main()
{
    cout << solution({"######",">#*###","####*#","#<#>>#",">#*#*<","######"}) << endl;
    return 0;
}

int solution(vector<string> board) {
    int answer = 0;
    int len = board.size();

    for(int index = 0; index < len; index++) {
        if(isGood(board, index, len)) {
            answer++;
        }
    }

    return answer;
}

bool isGood(vector<string> board, int start, int limit) {
    int count = 0;
    int curY = 0;
    int curX = start;

    while(curY < limit) {
        switch(board[curY][curX]) {
            case '#' : curY++; break;
            case '>' : curX++; break;
            case '<' : curX--; break;
            case '*':
                count++;
                if(count < 2) {
                    curY++;
                } else {
                    return false;
                }
                break;
            default : break;
        }
    }

    return true;
}