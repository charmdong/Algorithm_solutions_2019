#include <set>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	set<string> set1;
	string str;
	getline(cin, str);

	int check;
	check = str.find(' ');

	while (check != -1) {
		set1.insert(str.substr(0, check));
		str = str.substr(check + 1);
		check = str.find(' ');
	}
	set1.insert(str);

	cout << set1.size() << endl;
	return 0;
}