#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1; // 최소한 1개는 있어야 함.

    sort(routes.begin(), routes.end());

    int range = routes[0][1];
    for (int i = 0; i < routes.size() - 1; i++)
    {
        if(range > routes[i][1]) {
            range = routes[i][1];
        }

        if(range < routes[i+1][0]) {
            answer++;
            range = routes[i+1][1];
        }
    }

    return answer;
}

int main()
{

    return 0;
}