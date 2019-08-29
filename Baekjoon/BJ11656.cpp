#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> res;
void solution(string str);

int main()
{
	string str;
	cin >> str;
	solution(str);
	sort(res.begin(), res.end());
	for (string s : res)
		cout << s << endl;
	return 0;
}

void solution(string str) {
	for (int i = 0; i < str.length(); i++) {
		string sub = str.substr(i);
		res.push_back(sub);
	}
}