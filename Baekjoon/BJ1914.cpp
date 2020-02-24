/**
 * @author : donggun.chung
 * @date : 2020.02.07
 * @site : BOJ
 * @prob_Info : 1914 하노이 탑 
 * @time : 
 * @memory : 
 */

#include <iostream>
#include <cmath>
using namespace std;

int n;

void solution(int n, int from = 1, int to = 3, int assistant = 2);

int main()
{
    cin >> n;

    cout << pow(2, n) - 1 << endl;

    if(n <= 20) {
        solution(n);
    }

    return 0;
}

void solution(int n, int from, int to, int assistant){
    if(n == 1) {
        cout << from << " " << to << endl;
        return;
    }

    solution(n - 1, from, assistant, to);
    cout << from << " " << to << endl;
    solution(n - 1, assistant, to, from);    
}