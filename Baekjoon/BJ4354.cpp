#include <iostream>
#include <string>
#include <vector>
using namespace std;

int res(string str);
bool check(string str);

int main()
{
		vector<string> str;
		while (1) {
				string tmp;
				cin >> tmp;
				if (tmp == ".")
						break;
				str.push_back(tmp);
		}

		for (int i = 0; i < str.size(); i++)
				cout << res(str.at(i)) << "\n";

		return 0;
}

int res(string str) {
		int total = 1;
		
		// 자리수가 홀수인 경우
		if (str.length() % 2 != 0) 
				return check(str) ? str.length() : total;

		// 자리수가 짝수인 경우
		if (check(str))
				return str.length();

		for (int i = 2; i <= str.length(); i++) {
				string tmp = str.substr(0, i);
				for (int k = 1; k *i< str.length(); k++) {
						if (tmp == str.substr(k*i, i))
								total++;
						else {
								total = 1;
								break;
						}
				}
				if (total != 1)
						break;
		}

		return total;
}

bool check(string str) {
		char tmp = str.at(0);
		for (int i = 1; i < str.length(); i++) {
				if (tmp != str[i])
						return false;
		}
		return true;
}