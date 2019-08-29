/// 2514 : 문자열 찾기

#include <iostream>
#include <string>
#define K "KOI"
#define I "IOI"
using namespace std;

void total(string str);

int main()
{
		string str;
		cin >> str;
		total(str);
		return 0;
}

void total(string str) {
		int kTotal = 0, iTotal = 0;
		for (int i = 0; i < str.length() - 2; i++) {
				string tmp = str.substr(i, 3);
				if (tmp == K) kTotal++;
				else if (tmp == I) iTotal++;
		}
		cout << kTotal << "\n" << iTotal;
}