#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<string> a,b, res;
void solution();

int main()
{
	string tmp;

	cin >> n >> m;
	a.assign(n, "");
	b.assign(m, "");

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	solution();
	
	cout << res.size() << endl;
	for (string s : res)
		cout << s << endl;

	return 0;
}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] < b[j])
				break;
			if (a[i] == b[j]) {
				res.push_back(a[i]);
				break;
			}
		}
	}
}