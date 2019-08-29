#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ary;
int num[101];
int n;
void solution();

int main()
{
	cin >> n;
	ary.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> ary[i];
		num[ary[i]]++;
	}
	solution();
	return 0;
}

void solution() {
	sort(ary.begin(), ary.end());

	int diff=0;
	int check = 0;

	for (int i = 0; i < ary.size() - 1; i++) {
		if (ary[i] == ary[i + 1]) continue;
		else {
			if (diff != 0) {
				if (abs(ary[i] - ary[i + 1]) != diff) {
					cout << -1 << endl;
					return;
				}
			}
			else {
				diff = abs(ary[i] - ary[i + 1]);
			}
		}
	}

	for (int i = 1; i <= 100; i++) {
		if (num[i] > 0)
			check++;
	}
	if (check == 2) {
		if (diff % 2 == 0)
			diff /= 2;
	}
	cout << diff << endl;
}