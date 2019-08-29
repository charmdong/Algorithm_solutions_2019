/// 이항 계수

#include <iostream>
using namespace std;

int solution(int n, int r);

int main()
{
	int n, r;
	cin >> n >> r;
	cout << solution(n, r);
	return 0;
}

int solution(int n, int r) {
	if (n == r || r == 0) return 1;
	if (r == 1) return n;
	
	return n * solution(n - 1, r - 1) / r;
}