#include <iostream>

using namespace std;

long long fibo[91];
long long solution(int n);

int main()
{
    int n;

    cin >> n;
    cout << solution(n) << endl;

    return 0;
}

long long solution(int n) {
    fibo[0] = 0;
    fibo[1] = 1;

    for(int index = 2; index <= n; index++) {
        fibo[index] = fibo[index - 1] + fibo[index - 2];
    }

    return fibo[n];
}
