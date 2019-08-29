/// °Ë¿­ 2

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solution(string& str, string ban);

int main()
{
		string str, ban;
		cin >> str >> ban;
		solution(str, ban);
		cout << str << "\n";
		return 0;
}

void solution(string& str, string ban) {
		int pos = str.find(ban, 0);
		
		while (pos != string::npos) {
				str = str.replace(pos, ban.length(), "");
				pos = str.find(ban, 0);
		}
}