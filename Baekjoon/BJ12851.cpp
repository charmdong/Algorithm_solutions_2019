
#include <iostream>
#include <vector>
#include <queue>
#define DIST 0
#define CNT 1
using namespace std;

int N, K;
vector<vector<int>> dist;
vector<bool> visited;

int solution();

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;

    dist.assign(N, vector<int>(2, 0));

    cout << solution() << endl;

    return 0;
}

int solution() {
    int answer = 0;
    queue<int> q;
    vector<bool> visited(100001, false);

    visited[N] = true;
    q.push(N);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        cout << now << endl;

        if(now == K) {
            cout << dist[K][DIST] << endl;
            cout << dist[K][CNT] << endl;
            break;
        }

        for(int next : {now - 1, now + 1, now * 2}) {
            if(next >= 0 && next <= 100000) {
                if(!visited[next]) {
                    visited[next] = true;
                    dist[next][DIST] = dist[now][DIST] + 1;
                    dist[next][CNT]++;
                } else { // 이미 방문되어 있는 경우
                    if(dist[now][DIST] + 1 > dist[next][DIST]) {
                        continue;
                    }

                    if(dist[next][DIST] > dist[now][DIST] + 1) {
                        dist[next][DIST] = dist[now][DIST] + 1;
                        dist[next][CNT]++;
                    }

                    dist[next][CNT]++;
                }
                q.push(next);
            }
        }
    }
    
    return answer;
}