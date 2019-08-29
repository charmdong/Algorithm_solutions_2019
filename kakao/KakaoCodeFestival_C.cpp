#include <iostream>
#include <vector>
#include <string>
using namespace std;

string solution(string& str);

int main()
{
	string str;
	cin >> str;
	cout << solution(str);
	return 0;
}

string solution(string& str) {
	if (str.find("&&", 0) == string::npos)
		return str;
}