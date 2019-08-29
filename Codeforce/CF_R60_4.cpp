#include <iostream>
#include <string>
#include <algorithm>
#define MOD 1000000007
using namespace std;

long long n, m;
int solution();
long long combination(long long n, long long r);

int main() {
	cin >> n >> m;
	cout << solution() << endl;
	return 0;
}

int solution() {
	int res=1, q = n/m;
	
	for (int i = 1; i <= q; i++) {
		res += (combination(n - i, i) % MOD);
		res %= MOD;
	}
	return res % MOD;
}

long long combination(long long n, long long r) {
	if (n == r || r == 0)
		return 1;
	else
		return combination(n - 1, r - 1) + combination(n - 1, r);
}

// 5 2 ¸ò : 2 ÀÌ¹Ç·Î, 1ÀÎ °æ¿ì 2ÀÎ °æ¿ì »ý°¢.
// 10000 00100 00001 3C2 n-2 C 2  
// 11100 11001 10011 00111 4C1 n-1 C 1
// 11111
// n-¸ò C ¸ò

// 7-1 C 1 = 6
// 7-2 C 2 = 10
// 7-3 C 3 = 4

// 3-1 C 1 = 2
// 111