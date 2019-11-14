#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> pList);

int main()
{
    int n;
    vector<int> pList;

    cin >> n;
    pList.assign(n, 0);

    for(int index = 0; index < n; index++) {
        cin >> pList[index];
    }

    cout << solution(pList) << endl;
    
    return 0;
}

int solution(vector<int> pList) {
    int answer = 0;
    int total = 0;

    sort(pList.begin(), pList.end());

    for(int p : pList) {
        total += p;
        answer += total;
    }

    return answer;
}