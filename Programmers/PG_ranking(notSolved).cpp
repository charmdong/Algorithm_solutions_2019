#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> resultList);

int solution(int n, vector<vector<int>> resultList) {
    int answer = 0;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    for(vector<int> row : resultList) {
        int winner = row[0];
        int loser = row[1];

        graph[winner][loser] = 1;
        graph[loser][winner] = -1;
    }

    for(int player = 1; player <= n; player++) {
        for(int enemy = 1; enemy <= n; enemy++) {
            if(player == enemy) {
                continue;
            }

            if(graph[player][enemy] == -1) {
                for(int index = 1; index <= n; index++) {
                    if(graph[enemy][index] == -1){
                        graph[player][index] = -1;
                    }
                }
            }
        }
    }

    for(int row = 1; row <= n; row++) {
        int count = 0;
        for(int col = 1; col <= n; col++) {
            if(graph[row][col] != 0) {
                count++;
            }
        }
        if(count == n - 1) {
            answer++;
        }
    }

    return answer;
}

int main()
{
    cout << solution(5, {{4,3},{4,2},{3,2},{1,2},{2,5}}) << endl;
    return 0;
}