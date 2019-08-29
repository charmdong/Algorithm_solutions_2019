#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void res();

int main()
{
		res();
		return 0;
}

void res() {
		int num, val, rule;
		vector<int> v;

		cin >> num;
		cin >> rule;
		while (num--) {
				cin >> val;
				v.push_back(val);
		}

		rule ? sort(v.rbegin(), v.rend()) : sort(v.begin(), v.end());
		for (auto t : v) {
				cout << t << '\n';
		}
}