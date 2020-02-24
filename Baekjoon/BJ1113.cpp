#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> board;

int main()
{
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            scanf("%1d", &board[row][col]);
        }
    }

    return 0;
}

int solution() {
    /**
     * TODO: 수영장 테두리 안에 있는지를 확인해야 한다.
     * HOW? 각 좌표에서 주변을 탐색하다가 맵을 벗어나게 되는 좌표는 OUT!
     */ 
}