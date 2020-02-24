

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> timeList;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    timeList.assign(N, {0, 0});

    for(int index = 0; index < N; index++) {
        cin >> timeList[index].first >> timeList[index].second;
    }

    return 0;
}