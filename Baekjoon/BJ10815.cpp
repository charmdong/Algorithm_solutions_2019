#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> numList, searchList;

int main()
{
    cin >> n;
    numList.assign(n, 0);

    for(int index = 0; index < n; index++) {
        cin >> numList[index];
    }

    cin >> m;
    searchList.assign(m, 0);

    for(int index = 0; index < m; index++) {
        cin >> searchList[index];
    }

    for(int t : solution()) {
        cout << t << " ";
    }

    return 0;
}

vector<int> solution() {
    vector<int> answer;

    for(int index = 0; index < m; index++) {
        binary_search(numList.begin(), numList.end(), searchList[index] ?
        answer.push_back(1) : answer.push_back(0);
    }

    return answer;
}