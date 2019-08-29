#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k;
vector<int> ary;

long long solution();

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		ary.push_back(tmp);
	}
	cout << solution() << endl;
	return 0;
}

long long solution() {
	long long res = 0;
	sort(ary.begin(), ary.end());
	long long first = ary[ary.size() - 1];
	long long second = ary[ary.size() - 2];
	
	res = (m / (k + 1)) * (k*first + second) + (m % (k + 1)) * first;

	return res;
}