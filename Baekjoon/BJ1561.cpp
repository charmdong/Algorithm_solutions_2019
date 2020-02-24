#include <iostream>

using namespace std;

int numList[9];

void solution(int n, int m, int cnt = 0);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    solution(n, m);

    return 0;
}

void solution(int n, int m, int cnt) {
    if(m == cnt) {
        for(int index = 0; index < m; index++) {
            cout << numList[index] << " ";
        }
        cout << endl;
        return;
    }

    for(int num = 1; num <= n; num++) {
        numList[cnt] = num;
        solution(n, m, cnt + 1);
    }
}