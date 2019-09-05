#include <iostream>

using namespace std;

long long pinary[91];
long long solution(int n);

int main()
{
    int n;

    cin >> n;
    cout << solution(n) << endl;

    return 0;
}

long long solution(int n)
{
    pinary[1] = 1;
    pinary[2] = 1;

    for(int index = 3; index <= n; index++) {
        pinary[index] = pinary[index - 1] + pinary[index - 2];
    }

    return pinary[n];
}