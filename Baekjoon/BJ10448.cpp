#include <iostream>
using namespace std;

int test, k;
int solution(int k);

int main()
{
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> k;
		cout << solution(k) << endl;
	}
	return 0;
}

int solution(int k) {
	for (int i = 1; i*(i + 1) < 2 * k; i++) {
		for (int j = 1; j*(j + 1) < 2 * k; j++) {
			for (int w = 1; w*(w + 1) < 2 * k; w++) {
				if (2 * k == (i*(i + 1) + j * (j + 1) + w * (w + 1)))
					return 1;
			}
		}
	}
	return 0;
}