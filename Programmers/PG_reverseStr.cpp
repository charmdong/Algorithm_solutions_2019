#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseStr(string str);

int main()
{
	string test = "Zfedcba";
	cout << reverseStr(test) << endl;
	return 0;
}

string reverseStr(string str)
{
	char *tmp;
	tmp = new char[str.size() + 1];

	strcpy(tmp, str.c_str());
	sort(tmp, tmp + sizeof(tmp));
	str = tmp;
	reverse(str.begin(), str.end());

	delete tmp;
	return str;
}