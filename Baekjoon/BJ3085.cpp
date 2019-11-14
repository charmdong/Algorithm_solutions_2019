/**
 * 사탕 게임
 */ 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dy[] = {1, 0};
int dx[] = {0, 1};

int solution(vector<string>& board);
int getCount(vector<string> board);

int main() 
{
    int n;
    
    cin >> n;

    vector<string> board(n);

    for(int index = 0; index < n; index++) {
        cin >> board[index];
    }

    cout << solution(board) << endl;

    return 0;
}

int solution(vector<string>& board) {
    int answer = 0;
    int size = board.size();

    /**
     * 1. 오른쪽, 왼쪽에 대해서 스왑. 
     * 2. 행, 열에 대해서 연속된 갯수의 최대값 구하기.
     */ 

    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            for(int dir = 0; dir < 2; dir++) {
                int ny = row + dy[dir];
                int nx = col + dx[dir];

                if((-1 < ny && ny < size) && (-1 < nx && nx < size)) {
                    swap(board[row][col], board[ny][nx]);
                    answer = max(answer, getCount(board));
                    swap(board[row][col], board[ny][nx]);
                }
            }
        }
    }

    return answer;
}

int getCount(vector<string> board) {
    int count = 0;

    for(int row = 0; row < board.size(); row++) {
        int tmpCnt = 1;
        
        for(int col = 1; col < board.size(); col++) {
            if(board[row][col] == board[row][col - 1]) {
                tmpCnt++;
            } else {
                count = max(count, tmpCnt);
                tmpCnt = 1;
            }
        }
        count = max(count, tmpCnt);
    }

    for(int col = 0; col < board.size(); col++) {
        int tmpCnt = 1;

        for(int row = 1; row < board.size(); row++) {
            if(board[row][col] == board[row - 1][col]) {
                tmpCnt++;
            } else {
                count = max(count, tmpCnt);
                tmpCnt = 1;
            }
        }
        count = max(count, tmpCnt);
    }

    return count;
}