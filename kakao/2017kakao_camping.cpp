#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> data);

int main()
{
    cout << solution(4, {{0,1},{1,1},{0,2},{2,0}}) << endl;
    return 0;
}

int solution(int n, vector<vector<int>> data)
{
    int answer = 0;
    int sy = data[0][0];
    int sx = data[0][1];

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    visited[sy][sx] = true;
    

    return answer;
}