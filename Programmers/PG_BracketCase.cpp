/// �ùٸ� ��ȣ ����� �� - ��ͷ� ¥���ϳ�

#include <iostream>
#include <math.h>
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
	int res = 1;

	for (int i = 1; i <= n - 1; i++) {
		res += pow(3, i - 1);
	}

	return res;
}