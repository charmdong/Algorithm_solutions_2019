#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<string> board);
int getMinCount(vector<vector<char>> part);

int main()
{
    int n, m;
    vector<string> board;

    cin >> n >> m;

    board.assign(n, "");

    for(int row = 0; row < n; row++) {
        cin >> board[row];
    }

    cout << solution(board) << endl;

    return 0;
}

int solution(vector<string> board) {
    int answer = 8 * 8;
    int rowLen = board.size();
    int colLen = board[0].size();

    for(int y = 0; y <= rowLen - 8; y++) {
        for(int x = 0; x <= colLen - 8; x++) {
            vector<vector<char>> part(8, vector<char>(8));
            int partY = 0;
            int partX = 0;

            // 8 * 8 선택
            for(int row = y; row < y + 8; row++) {
                for(int col = x; col < x + 8; col++) {
                    part[partY][partX++] = board[row][col];
                }
                partY++;
                partX = 0;
            }

            int partRes = getMinCount(part);
            answer = (answer > partRes) ? partRes : answer;
        }
    }

    return answer;
}

int getMinCount(vector<vector<char>> part) {
    int answer = 0;

    int wCount = 0;
    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++) {
            if((row + col) % 2 == 0) {
                if(part[row][col] != 'W') {
                    wCount++;
                }
            } else {
                if(part[row][col] != 'B') {
                    wCount++;
                }
            }
        }
    }

    int bCount = 0;
    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++) {
            if((row + col) % 2 == 0) {
                if(part[row][col] != 'B') {
                    bCount++;
                }
            } else {
                if(part[row][col] != 'W') {
                    bCount++;
                }
            }
        }
    }
    
    answer = (wCount > bCount) ? bCount : wCount;
    return answer;
}