/// 1,2,3 으로 숫자 나타내기

#include <iostream>
using namespace std;

int ary[] = { 0,1,2,3 };
int total = 0;
void solution(int n);

int main()
{
	int caseCnt, n;
	cin >> caseCnt;
	while (caseCnt--) {
		cin >> n;
		solution(n);
		cout << total << "\n";
		total = 0;
	}
	return 0;
}

void solution(int n) {
	if (n == 0) {
		total++;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (n - ary[i] >= 0)
			solution(n - ary[i]);
	 }
}