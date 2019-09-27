/**
 * PG : 카펫 - 완전탐색
 */ 

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;

    for(int row = 1; row <= red / 2; row++) {
        if(red % row == 0) {
            int col = red / row;

            if((col + 2) * 2 + row * 2 == brown) {
                answer.push_back(col + 2);
                answer.push_back(row + 2);
                break;
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> res = solution(24, 24);
    
    for(int t : res) {
        cout << t << " ";
    }

    return 0;
}