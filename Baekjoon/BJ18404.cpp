/**
 * @author : donggun.chung
 * @date : 2020.02.23
 * @site : BOJ
 * @prob_Info : 18404 현명한 나이트
 * @time : 12ms
 * @memory : 3180KB
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, ky, kx;
vector<vector<int>> cnt;
vector<vector<bool>> visited;
vector<pair<int, int>> enemy;

int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void bfs();

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    cin >> ky >> kx;

    cnt.assign(N + 1, vector<int>(N + 1, 0));
    visited.assign(N + 1, vector<bool>(N + 1, false));
    enemy.assign(M, {0, 0});
    
    for(int index = 0; index < M; index++) {
        cin >> enemy[index].first >> enemy[index].second;
    }

    bfs();
    for(auto e : enemy) {
        cout << cnt[e.first][e.second] << " ";
    }
    cout << endl;

    return 0;
}

void bfs() {
    queue<pair<int, int>> q;

    visited[ky][kx] = true;
    q.push({ky, kx});

    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for(int dir = 0; dir < 8; dir++) {
            int ny = now.first + dy[dir];
            int nx = now.second + dx[dir];

            if(ny > 0 && ny <= N && nx > 0 && nx <= N) {
                if(!visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                    cnt[ny][nx] = cnt[now.first][now.second] + 1;
                }
            }
        }
    }
}