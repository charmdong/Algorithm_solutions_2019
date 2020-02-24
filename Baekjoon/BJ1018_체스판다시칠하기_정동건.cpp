
#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<vector<int>> board;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n;
    board.assign(m, vector<int>(n, 0));

    for(int row = 0; row < m; row++) {
        for(int col = 0; col < n; col++) {
            scanf("%1d", &board[row][col]);
        }
    }

    

    return 0;
}