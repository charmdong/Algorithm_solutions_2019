#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> visited;
vector<vector<int>> graph;

vector<int> solution(vector<int> cook_times, vector<vector<int>> order, int k);
void dfs(vector<int> cook_times, int &answer, int index, int &count, int total = 0);

int main()
{
    vector<int> ans = solution({5,3,2}, {{1,2}, {2,3}, {1,3}}, 3);
    cout << ans[0] << " "<<ans[1] << endl;
    return 0;
}

vector<int> solution(vector<int> cook_times, vector<vector<int>> order, int k) {
    vector<int> res;
    int cookLen = cook_times.size();
    int answer = 0;
    int count = 0;

    visited.assign(cookLen, false);
    graph.assign(cookLen + 1, vector<int>());

    for(auto v: order) {
        int next = v[1];
        int pre = v[0];
        graph[next].push_back(pre);
    }

    dfs(cook_times, answer, k, count, 0);
    cout << endl;
    res.push_back(count);
    res.push_back(answer);

    return res;
}

void dfs(vector<int> cook_times, int &answer, int index, int &count, int total) {
    cout << index << " ";
    if(graph[index].size() == 0) {
        answer = max(answer, total + cook_times[index - 1]);
        count++;
        return;
    }

    for(int i = 0; i <graph[index].size(); i++) {
        int pre = graph[index][i];

        if(!visited[pre -1]) {
            visited[pre - 1] = true;
            dfs(cook_times, answer, pre, count, total + cook_times[index - 1]);
            visited[pre - 1] = false;
        }
    }
}