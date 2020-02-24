/**
 * 이분 탐색
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main()
{
    int num;
    vector<int> numList;

    cin >> n;
    numList.assign(n, 0);

    for(int index = 0; index < n; index++) {
        cin >> numList[index];
    }

    sort(numList.begin(), numList.end());

    cin >> m;

    for(int index = 0; index < m; index++) {
        cin >> num;
        if(binary_search(numList.begin(), numList.end(), num)){
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}