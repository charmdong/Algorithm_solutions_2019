/**
 * @author : donggun.chung
 * @date : 2020.02.07
 * @site : BOJ
 * @prob_Info : 10819 차이를 최대로 
 * @time : 4ms
 * @memory : 1984KB
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, answer;
vector<int> list, res;
vector<bool> visited;

void dfs(int cnt = 0);
int getTotal();

int main()
{
    cin >> n;

    list.assign(n, 0);
    visited.assign(n ,false);

    for(int index = 0; index < n; index++) {
        cin >> list[index];
    }

    dfs();

    cout << answer << endl;

    return 0;
}

void dfs(int cnt) {
    if(cnt == n) {
        int tmp = getTotal();

        if(tmp > answer) {
            answer = tmp;
        }
    }

    for(int index = 0; index < n; index++) {
        if(visited[index]) {
            continue;
        }

        visited[index] = true;
        res.push_back(list[index]);
        dfs(cnt + 1);
        res.pop_back();
        visited[index] = false;
    }
}

int getTotal() {
    int total = 0;

    for(int index = 0; index < n - 1; index++) {
        total += abs(res[index] - res[index + 1]);
    }

    return total;
}