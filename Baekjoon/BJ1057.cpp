#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int solution(int n, int k, int l);

int main()
{
    int n, kIndex, lIndex;

    cin >> n >> kIndex >> lIndex;
    cout << solution(n, kIndex, lIndex) << endl;

    return 0;
}

int solution(int n, int k, int l) {
    if(n < k || n < l) {
        return -1;
    }
    
    int answer = 0;

    while(k != l) {
        k = k/2 + k%2;
        l = l/2 + l%2;
        answer++;
    }

    return answer;
}