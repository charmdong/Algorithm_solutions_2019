
#include <iostream>
#include <vector>

using namespace std;

int N;
bool flag;
vector<vector<char>> board;
vector<pair<int, int>> teacher, obstacle;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void solution();
bool isDetected();
bool isInBoard(int y, int x);
void setObstacle(int = 0, int = 0);

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    board.assign(N, vector<char>(N, 0));

    // 맵 상태 입력 및 선생님들의 좌표 확인
    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            scanf(" %c", &board[row][col]);

            if(board[row][col] == 'T') {
                teacher.push_back({row, col});
            }
        }
    }

    solution();

    return 0;
}

void solution() {
    setObstacle();
    flag ? cout << "YES\n" : cout << "NO\n";
}

void setObstacle(int R, int C) {
    if(flag) return;

    if(obstacle.size() == 3) {
        // for(auto o : obstacle) {
        //     cout << "[" << o.first << ", " << o.second << "] ";
        // }
        // cout << endl;
        // return;
        
        if(!isDetected()) {
            flag = true;
        }

        return;
    }

    for(int row = R; row < N; row++) {
        if(row > R) {
            C = 0;
        }
        for(int col = C; col < N; col++) {
            if(board[row][col] != 'X') continue;
            
            obstacle.push_back({row, col});
            
            if(col + 1 <= N) {
                setObstacle(row, col + 1);
            } else {
                setObstacle(row + 1, 1);
            }

            obstacle.pop_back();
        }
    }
}

bool isDetected() {
    vector<vector<char>> copied = board;

    // 장애물 설치
    for(pair<int, int> o : obstacle) {
        copied[o.first][o.second] = 'O';
    }

    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            cout << copied[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(pair<int, int> t : teacher) {
        for(int dir = 0; dir < 4; dir++) {
            int ny = t.first + dy[dir];
            int nx = t.second + dx[dir];

            // 현재 방향으로 학생이 있는지 탐색
            while(isInBoard(ny, nx)) {
                char current = copied[ny][nx];
                // 학생이 탐지된 경우
                if(current == 'S') {
                    return true;
                } 
                // 장애물을 만난 경우
                else if(current == 'O') {
                    break;
                }
                // 복도이거나 선생님인 경우 다음 칸으로 이동
                else {
                    ny += dy[dir];
                    nx += dx[dir];
                }
            }
        }
    }

    return false;
}

bool isInBoard(int y, int x) {
    return (y > -1 && y < N && x > -1 && x < N);
}