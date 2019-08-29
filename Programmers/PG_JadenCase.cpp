/// JadenCase 문자열 만들기

#include <iostream>
#include <string>

using namespace std;

string solution(string str);

int main()
{
		string str;
		getline(cin, str);
		cout << solution(str) << "\n";
		return 0;
}

string solution(string str) {
		string res;
		res += toupper(str[0]);

		for (int i = 1; i < str.length(); i++)
				res += (res[i - 1] == ' ') ? toupper(str[i]) : tolower(str[i]);
		return res;
}