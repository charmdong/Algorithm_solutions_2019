/// 1566 : 소수 문자열

#include <iostream>
#include <string>
using namespace std;

bool prime[26] = { false };

bool isPrime(int n);
void primeString(string str, int *cnt);

int main()
{
		string str;
		int cnt[26] = { 0 };
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
				cnt[str[i] - 65]++;
		}
		primeString(str, cnt);
		return 0;
}

bool isPrime(int n) {
		if (n==0 || n == 1) return false;
		else if (n == 2) return true;
		else {
				for (int i = 2; i < n; i++) {
						if (n % i == 0)
								return false;
				}
				return true;
		}
}

void primeString(string str, int *cnt) {
		for (int i = 0; i < 26; i++)
				prime[i] = isPrime(cnt[i]);

		bool check = false;
		for (int i = 0; i < 26; i++) {
				// 소수인 경우
				if (prime[i]) {
						printf("%c", i + 65);
						check = true;
				}
		}
		if (!check)
				cout << "NONE\n";
}