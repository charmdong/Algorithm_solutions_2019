/**
 * 시간복잡도 : O(V+E)
 * 공간복잡도 : O(V+E)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visited(100001, false);
vector<vector<int>> board(100001, vector<int>());

int bfs(int index);

int main()
{
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int src, des;

        cin >> src >> des;
        board[src].push_back(des);
        board[des].push_back(src);
    }

    cout << bfs(100001);

    return 0;
}

int bfs(int limit)
{
    int ans = 0;

    for (int index = 1; index <= limit; index++)
    {
        if (!board[index].empty() && !visited[index]) {
            queue<int> q;
            q.push(index);
            visited[index] = true;

            while(!q.empty()) {
                int now = q.front();
                q.pop();

                for(int i = 0; i < board[now].size(); i++) {
                    int next = board[now][i]; // 인접 친구 찾기

                    if(!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }

            ans++;
        }
    }

    return ans;
}