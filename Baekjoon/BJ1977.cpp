/// 완전제곱수

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void solution(int n, int m);

int main()
{
	int n, m;
	cin >> n >> m;
	solution(n, m);
	return 0;
}

void solution(int n, int m) {
	vector<int> res(m + 1, 0);

	int start = sqrt(n);
	int end = sqrt(m);
	int total = 0;

	if (start == end) {
		cout << -1 << endl;
		return;
	}

	start = (start*start == n) ? start : start + 1;

	for (int i = start; i <= end; i++) {
		res[i*i] = 1;
		total += i * i;
	}

	cout << total << endl;
	cout << start * start << endl;
}