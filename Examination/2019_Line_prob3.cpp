#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<pair<int, int>> toiletList);

int main()
{
    int n;
    vector<pair<int, int>> toiletList;

    cin >> n;
    toiletList.assign(n, {0, 0});

    for(int i=0; i<n; i++) {
        cin >> toiletList[i].first >> toiletList[i].second;
    }

    sort(toiletList.begin(), toiletList.end());

    cout << solution(toiletList) << endl;

    return 0;
}

int solution(vector<pair<int ,int>> toiletList) {
    int len = toiletList.size();
    int backTime = toiletList[0].second;
    int toiletCount = 1;

    for(int index = 1; index < len; index++) {
        int curGoTime = toiletList[index].first;
        int curBackTime = toiletList[index].second;

        if (curGoTime < backTime) {
            backTime = min(backTime, curBackTime);
            toiletCount++;
        }
    }

    return toiletCount;
}