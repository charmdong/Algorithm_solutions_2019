#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> list;

void solution(int before = 1, int cnt = 1);

int main()
{
    cin >> n >> m;
    list.assign(n + 1, 0);

    solution();
    return 0;
}

void solution(int before, int cnt) {
    if(cnt == m + 1) {
        for(int index = 1; index <= m; index++) {
            cout << list[index] << " ";
        }
        cout << "\n";

        return;
    }

    for(int num = before; num <= n; num++) {
        list[cnt] = num;
        solution(num, cnt + 1);
    }
}