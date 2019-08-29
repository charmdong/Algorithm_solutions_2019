#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> st;
int B, C;
long solution();

int main()
{
	cin >> n;
	st.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> st[i];
	cin >> B >> C;
	cout << solution() << endl;
	return 0;
}

long solution() {
	long ans = 0;

	for (int i = 0; i < n; i++) {
		ans++;
		st[i] -= B;
		if (st[i] > 0) {
			ans += st[i] / C;
			if (st[i] % C > 0)
				ans++;
		}
	}

	return ans;
}