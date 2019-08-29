#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num(4, 0);
void solution();

int main()
{
	for (int i = 0; i < 4; i++)
		cin >> num[i];
	sort(num.begin(), num.end());
	solution();
	return 0;
}

void solution() {
	int a, b, c;
	a = num[3] - num[1];
	b = num[3] - num[2];
	c = num[3] - num[0];

	cout << a << " " << b << " " << c << endl;
}

// a, b, c
// a+b, b+c, a+c, a+b+c �� �־����µ�, a, b, c�� ���ض�
// a+b+c�� ���� Ŭ ���̰�, a+b, b+c, a+c�� ���� a+b+c�� 2���̴�.
// num[3] = a+b+c
// c = num[3] - num[0];
// b = num[3] - num[2];
// a = num[3] - num[1];