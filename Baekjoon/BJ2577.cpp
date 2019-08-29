/// 숫자의 개수

#include <iostream>
using namespace std;

void solution(int a, int b, int c);

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	solution(a, b, c);
	return 0;
}

void solution(int a, int b, int c) {
	int ary[10] = { 0 };
	int total = a * b * c;

	while (1) {
		if (total / 10 == 0) {
			ary[total]++;
			break;
		}
		ary[total % 10]++;
		total /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << ary[i] << endl;
}