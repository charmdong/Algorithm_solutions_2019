#include <iostream>

using namespace std;

int L, A, B, C, D;

int main()
{
    int max = 0;
    int math, kor;

    cin >> L >> A >> B >> C >> D;

    kor = (A % C != 0) ? (A / C + 1) : (A / C);
    math = (B % D != 0) ? (B / D + 1) : (B / D);
    max = (kor > math) ? kor : math;

    cout << L - max << endl;

    return 0;
}