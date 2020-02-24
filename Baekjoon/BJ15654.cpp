#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> list;
vector<int> numList;
vector<bool> visited;

void solution(int cnt = 0);

int main()
{
    cin >> n >> m;
    numList.assign(m, 0);
    list.assign(n, 0);
    visited.assign(n, false);

    for(int index = 0; index < n; index++) {
        cin >> list[index];
    }

    sort(list.begin(), list.end());
    solution();
    return 0;
}

void solution(int cnt) {
    if(cnt == m) {
        for(int index = 0; index < m; index++) {
            cout << numList[index] << " ";
        }
        cout << "\n";

        return;
    }

    for(int index = 0; index < n; index++) {
        int next = list[index];

        if(!visited[index]) {
            visited[index] = true;
            numList[cnt] = next;
            solution(cnt + 1);
            visited[index] = false;
        }
    }
}