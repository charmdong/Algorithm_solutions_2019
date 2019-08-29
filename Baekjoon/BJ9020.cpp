/// ∞ÒµÂπŸ»Â¿« √ﬂ√¯

#include <iostream>
#include <vector>
using namespace std;

void primeParsing(vector<int>& v,int n);
void solution(int n);

int main()
{
		int testCase, n;
		cin >> testCase;
		while (testCase--) {
				cin >> n;
				solution(n);
		}
		return 0;
}

void solution(int n) {
		int i, k, mid = n / 2;
		vector<int> v;
		primeParsing(v, n);
		for (i = k = mid; i <= n; i++, k--) {
				if (v[i] != 0 && v[k] != 0 && v[i] + v[k] == n) {
						cout << v[k] << " " <<v[i] << "\n";
						return;
				}
		}
}

void primeParsing(vector<int>& v, int n) {
		v.assign(n + 1, 0);

		for (int i = 2; i <= n; i++)
				v[i] = i;

		for (int i = 2; i <= n; i++) {
				if (v[i] == 0) continue;
				for (int k = i + i; k <= n; k += i)
						v[k] = 0;
		}
}