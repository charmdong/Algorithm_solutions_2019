/**
 * dfs
 * 시간복잡도 : O(2^n)
 * 공간복잡도 : O(n)
 */ 
#include <iostream>
#include <vector>
using namespace std;

int n;
int ans;
vector<int> startDateList;
vector<int> durationList;
vector<int> priceList;
vector<int> resIndex;
vector<int> answer;

void solution(int index, int curDate = 0, int totalPrice = 0);

int main()
{
    cin >> n;

    startDateList.assign(n, 0);
    durationList.assign(n, 0);
    priceList.assign(n, 0);

    for(int i=0; i<n; i++) {
        cin >> startDateList[i] >> durationList[i] >> priceList[i];
    }

    for(int i=0; i<n; i++) {
        solution(i);
    }

    cout << ans << endl;
    for(int t : answer) {
        cout << startDateList[t] << " " << durationList[t] << endl;
    }

    return 0;
}

void solution(int current, int curDate, int totalPrice) {
    resIndex.push_back(current);
    totalPrice += priceList[current];

    for(int next = current + 1; next < n; next++) {
        if(curDate + durationList[current] < startDateList[next]) {
            solution(next, startDateList[next], totalPrice);
        }
    }

    if(ans < totalPrice ) {
        ans = totalPrice;
        answer = resIndex;
    }

    resIndex.pop_back();
}