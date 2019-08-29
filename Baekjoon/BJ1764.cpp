#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> hear;
vector<string> res;

void solution(int m);

int main()
{
	int n, m;
	cin >> n >> m;

	hear.assign(n, "");

	for(int i=0; i<n; i++) {
		cin >> hear[i];
	}

	sort(hear.begin(), hear.end());
	solution(m);

	return 0;
}

void solution(int m) {
	string str;
	for(int i=0; i<m; i++) {
		cin >> str;

		if(binary_search(hear.begin(), hear.end(), str)) {
			res.push_back(str);
		}
	}

	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for(string s : res) {
		cout << s << endl;
	}
}