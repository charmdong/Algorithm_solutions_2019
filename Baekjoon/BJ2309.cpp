/// ¿œ∞ˆ ≥≠¿Ô¿Ã

#include <iostream>
#include <vector>
#include <algorithm>
#define TOTAL 100
using namespace std;

void solution(vector<int>& v);

int main()
{
	int tall;
	vector<int> v;

	for (int i = 0; i < 9; i++) {
		cin >> tall;
		v.push_back(tall);
	}
	sort(v.begin(), v.end());
	solution(v);
	return 0;
}

void solution(vector<int>& v) {
	int sum=0;
	for (auto t : v)
		sum += t;

	sum -= TOTAL;

	int i, k, check = 0;
	for (i = 0; i < 8; i++) {
		for (k = i + 1; k < 9; k++) {
			if (v[i] + v[k] == sum) {
				check = 1;
				break;
			}
		}
		if (check)break;
	}

	for (auto t : v) {
		if (t == v[i] || t == v[k]) continue;
		cout << t << endl;
	}
}