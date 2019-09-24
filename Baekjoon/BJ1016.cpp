/// ���� ������

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int solution(long long min, long long max);

int main()
{
	long long min, max;
	cin >> min >> max;
	cout << solution(min, max);
	return 0;
}

int solution(long long min, long long max) {
	vector<long long> prime(max + 1, 0);
	vector<long long> allPrime;
	int cnt = 0;

	for (long long i = 2; i <= max; i++)
		prime[i] = i;

	for (long long i = min; i <= max; i++) {
		if (prime[i] == 0) continue;
		for (int k = i + i; k <= max; k += i)
			prime[k] = 0;
	}

	for (int i = min; i <= max; i++) {
		if (prime[i] != 0)
			allPrime.push_back(i);
	}

	
}