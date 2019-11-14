#include <iostream>
#include <vector>

using namespace std;

class shark {
    public:
        int y, x, speed, dir, size;
        bool death;

        shark() {y = x = speed = dir = size = death = 0;}
        shark(int y, int x, int sp, int d, int s) : y(y), x(x), speed(sp), dir(d), size(s) {death = false;}
};

int n, m, num;
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, 1, -1};
vector<shark> sList;
vector<vector<int>> board;

int solution();
bool isInBoard(int y, int x);

void print() {
    for(int row = 1; row <= n; row++) {
        for(int col = 1; col <= m; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    cin >> n >> m >> num;

    board.assign(n + 1, vector<int>(m + 1, 0));

    sList.push_back(shark());
    for(int index = 1; index <= num; index++) {
        int y, x, sp, d, s;

        cin >> y >> x >> sp >> d >> s;
        sList.push_back(shark(y, x, sp, d, s));
        board[y][x] = index;
    }

    cout << solution() << endl;

    return 0;
}

/**
 * 1. 낚시왕이 한 칸 움직인 뒤 땅과 가장 가까운 상어를 잡는다 answer += 잡은 상어 크기
 * 2. 상어들이 모두 이동한다.
 *      2-1. 상어들의 다음 위치를 vector<pair<pair<int, int,> shark>> nextPos에 push_back한다.
 *      2-2. 다음 위치를 구한 상어의 현재 위치 clear();
 *      2-3. board에 nextPos에 해당하는 상어들을 위치시키면서 겹치는 곳은 처리
 */ 
int solution() {
    int answer = 0;

    if(sList.size() == 1) {
        return answer;
    }

    for(int col = 1; col <= m; col++) {
        print();
        for(int row = 1; row <= n; row++) {
            int index = board[row][col];
            
            if(index) {
                sList[index].death = true;
                answer += sList[index].size;
                board[row][col] = 0;
                break;
            }
        }

        if(col == m) {
            break;
        }

        vector<vector<int>> nextPos(n + 1, vector<int>(m + 1, 0));

        for(int index = 1; index <= num; index++) {
            shark now = sList[index];
            
            if(now.death) {
                continue;
            }

            int ny = now.y;
            int nx = now.x;
            int speed = now.speed;

            for(int mov = 0; mov < speed; mov++) {
                if(!isInBoard(ny + dy[now.dir], nx + dx[now.dir])) {
                    now.dir += (now.dir % 2 == 0) ? -1 : 1;
                }

                ny += dy[now.dir];
                nx += dx[now.dir];
            }

            if(nextPos[ny][nx]) {
                if(sList[nextPos[ny][nx]].size < now.size) {
                    sList[nextPos[ny][nx]].death = true;
                    nextPos[ny][nx] = index;
                } else {
                    sList[index].death = true;
                }
            } else {
                nextPos[ny][nx] = index;
                sList[index].y = ny;
                sList[index].x = nx;
                sList[index].dir = now.dir;
            }
        }

        board = nextPos;
    }

    return answer;
}

bool isInBoard(int y, int x) {
    if(y > 0 && y <= n) {
        if(x > 0 && x <= m) {
            return true;
        }
        return false;
    }
    return false;
}

// map<int, shark> 사용
// board[row][col] = size