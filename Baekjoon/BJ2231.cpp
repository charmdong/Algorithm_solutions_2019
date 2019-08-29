/// ºÐÇØÇÕ

#include <iostream>
using namespace std;

int solution(int n);

int main()
{
	int n;
	cin >> n;
	cout << solution(n);
	return 0;
}

int solution(int n) {
	int origin = n;
	int len = 0;

	while (1) {
		len++;
		if (origin / 10 == 0)
			break;
		origin /= 10;
	}

	int min = n - 9 * len;
	int check = 0;

	for (int i = min; i <= n + 1; i++) {
		int testNum = i;
		int testTotal = testNum;

		while (1) {
			testTotal += (testNum % 10);
			if (testTotal > n || testNum / 10 == 0)break;
			testNum /= 10;
		}

		if (testTotal == n) {
			check = i;
			break;
		}
	}

	return check;
}