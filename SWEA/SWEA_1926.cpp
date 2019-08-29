#include <iostream>
using namespace std;

int n;
int solution(int n);

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		int num = solution(i);
		if (!num)
			cout << i << " ";
		else {
			for (int j = 0; j < num; j++)
				cout << "-";
			cout << " ";
		}
	}

	return 0;
}

int solution(int n) {
	int res = 0;
	int tmp = n;

	while (tmp != 0) {
		int rem = tmp % 10;
		if (rem == 3 || rem == 6 || rem == 9)
			res++;
		tmp /= 10;
	}

	return res;
}