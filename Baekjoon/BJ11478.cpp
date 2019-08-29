#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	set<string> s;
	string str;

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; ; j++) {
			if (str.length() - j <= i)
				break;
			s.insert(str.substr(0 + j, 1 + i));
		}
	}
	cout << s.size() << endl;

	return 0;
}