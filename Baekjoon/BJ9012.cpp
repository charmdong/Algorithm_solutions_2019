#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool solution(string str);

int main()
{
	int t;
	string str;

	cin >> t;
	while (t--) {
		cin >> str;
		if (solution(str))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}

bool solution(string str) {
	stack<char> s;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(')
			s.push(str[i]);
		else {
			if (s.empty())
				return false;
			s.pop();
		}
	}
	if (!s.empty())
		return false;
	return true;
}