/// 감소하는 수

#include <iostream>
#include <string>
using namespace std;

long long solution(int n);

int main()
{
	int n;
	cin >> n;
	cout << solution(n);
	return 0;
}

long long solution(int n) {
	if (n < 10)
		return n;

	long long num = 9; // 몇 번째 감소하는 수인지..

	for (int i = 10; ; i++) {
		string str = to_string(i);
		bool check = true;
		for (int k = 0; k < str.length() - 1; k++) {
			if (str[k]-'0' <= str[k + 1]-'0') {
				check = false;
				break;
			}
		}
		if (check)
			num++;
		if (num == n)
			return i;
	}

	return -1;
}