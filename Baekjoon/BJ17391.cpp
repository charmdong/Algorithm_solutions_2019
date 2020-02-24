
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> board, item;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int bfs();

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    board.assign(N + 1, vector<int>(M + 1, 0));
    item = board;

    for(int row = 1; row <= N; row++) {
        for(int col = 1; col <= M; col++) {
            cin >> board[row][col];
        }
    }

    cout << bfs() << endl;

    return 0;
}

int bfs() {
    queue<pair<int, int>> q;
    int iCnt = 0;

    q.push({1, 1});

    while(!q.empty()) { // 각 경우마다 부스터 량이 다르니까 관리해줘야 함
        pair<int, int> now = q.front();
        q.pop();

        if(now == make_pair(N, N)) {
            return item[N][N];
        }

        iCnt += board[now.first][now.second];


    }
}