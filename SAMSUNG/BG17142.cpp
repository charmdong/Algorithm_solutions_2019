#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int n, m;
vector<pair<int ,int>> virus;
vector<vector<bool>> visited;
vector<vector<int>> board;
vector<vector<int>> dist;

int solution();
void getCombination(vector<vector<int>>& totalList, vector<int>& active, int index, vector<bool> used);
int bfs(vector<int> activeIndex);

int main()
{
    cin >> n >> m;

    board.assign(n, vector<int>(n, 0));

    // input the board
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            cin >> board[row][col];

            if(board[row][col] == 2) {
                virus.push_back({row, col});
            }
        }
    }

    cout << solution() << endl;

    return 0;
}

void getCombination(vector<vector<int>>& totalList, vector<int>& active, int index, vector<bool> used) {
    if(active.size() == m) {
        totalList.push_back(active);
        return;
    }

    for(int now = index; now < virus.size(); now++) {
        if(!used[now]) {
            used[now] = true;
            active.push_back(now);
            getCombination(totalList, active, now + 1, used);
            active.pop_back();
            used[now] = false;
        }
    }
}

int solution() {
    int answer = 50 * 50;
    vector<vector<int>> indexList;
    vector<int> active;
    vector<bool> used(virus.size(), false);

    // 1. index 조합을 구한다 
    getCombination(indexList, active, 0, used);

    vector<int> resList;
    // 2. 해당 활성화 바이러스 목록을 가지고 bfs, visited 할당
    for(auto a : indexList) {
        visited.assign(n, vector<bool>(n, false));
        dist.assign(n, vector<int>(n, 0));
        int res = bfs(a);
        if(res >= 0 && res < answer) {
            answer = res;
        }
    }

    if(answer == 50 * 50) {
        answer = -1;
    }

    return answer;
}

int bfs(vector<int> activeIndex) {
    int answer = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> tmp = board;

    for(int index : activeIndex) {
        pair<int, int> active = virus[index];

        q.push(active);
        visited[active.first][active.second] = true;
    }

    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int ny = now.first + dy[dir];
            int nx = now.second + dx[dir];

            if(ny > -1 && ny < n && nx > - 1&& nx < n) {
                if(!visited[ny][nx]) {
                    // 비활성화 바이러스인 경우
                    if(tmp[ny][nx] == 2) {
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                        dist[ny][nx] = dist[now.first][now.second] + 1;
                        continue;
                    }

                    // 벽이 아닌 경우                  
                    if(tmp[ny][nx] == 0) {
                        tmp[ny][nx] = 2;
                        dist[ny][nx] = dist[now.first][now.second] + 1;
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                        answer = (answer < dist[ny][nx]) ? dist[ny][nx] : answer;
                    }
                }
            }
        }
    }
    
    for(auto lst : tmp) {
        for(auto t : lst) {
            if(t == 0) {
                return -1;
            }
        }
    }

    return answer;
}