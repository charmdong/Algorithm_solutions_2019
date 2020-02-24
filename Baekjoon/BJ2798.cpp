#include <iostream>
#include <vector>

using namespace std;

int diff, answer;

void solution(int m, vector<int> numList, int index = 0, int total = 0, int cnt = 0);

int main()
{
    int n, m, num;
    vector<int> numList;

    cin >> n >> m;
    
    for(int index = 0; index < n; index++) {
        cin >> num;
        numList.push_back(num);
    }
    
    diff = m;
    solution(m, numList);
    cout << answer << endl;

    return 0;
}

void solution(int m, vector<int> numList, int index, int total, int cnt) {
    if(total > m) {
        return;
    }    

    if(cnt == 3) {
        if(m - total < diff) {
            diff = m - total;
            answer = total;
        }
        return;
    }

    for(int next = index; next < numList.size(); next++) {
        solution(m, numList, next + 1, total + numList[next], cnt + 1);
    }
}