#include <iostream>
#include <vector>
using namespace std;

int primeList[1000001] = {1, };
//vector<int> primes;

void getPrime();
void solution(int n);

int main()
{
    int n;

    while(true) {
        cin >> n;
        if(n == 0) {
            break;
        }

        solution(n);
    }
    return 0;
}
// TLE
void getPrime() {
    for(int index = 2; index <= 1000000; index++) {
        for(int next = index; next <= 1000000; next += next) {
            if(primeList[next]) {
                primeList[next] = 0;
            }
        }
    }
}

void solution(int n) {
    int prime1, prime2;

    for(int index = 2; index < n; index++) {
        if(primeList[index]) {
            if(primeList[n - index]) {
                cout << n << " = " << primeList[index] << " + " << primeList[n - index] << endl;
                return;
            }
        }
    }

    cout << "Goldbach's conjecture is wrong." << endl;
}