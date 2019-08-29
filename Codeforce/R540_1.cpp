#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

long long ans;

int main()
{
	long long q,n, a, b;
	
	cin >> q;
	while (q--) {
		ans = LLONG_MAX;
		cin >> n >> a >> b;

		if (2 * a <= b)
			ans = a * n;
		else {
			for (long long i = 0; i <= n; i++) {
				for (long long j = (n - i) / 2; j >= 0; j--) {
					if (i + 2 * j == n) {
						if (ans > a*i + b * j)
							ans = a * i + b * j;
					}
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}