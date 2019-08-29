/// 소수의 합

#include <iostream>
#include <vector>
using namespace std;

long long solution(int n) {
		/*if (n == 2) return 2;

		for (int i = 2; i < n; i++) {
				if (n % i == 0)
						return solution(n-1);
		}
		return n + solution(n - 1);*/
		if (n == 2) return 2;

		vector<int> prime;
		long long total = 0;
		prime.push_back(2);

		for (int i = 3; i <= n; i++) {
				bool check = true;
				for (int k = 2; k < i; k++) {
						if (i % k == 0) {
								check = false;
								break;
						}
				}
				if (check)
						prime.push_back(i);
		}

		for (int a : prime)
				total += a;
		return total;

}

int main() {
		int n;
		cin >> n;
		cout << solution(n);
		return 0;
}