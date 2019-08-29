/// 2604 : ±×¸©

#include <iostream>
#include <string>
using namespace std;

void height(string str);

int main()
{
		string str;
		cin >> str;
		height(str);
		return 0;
}

void height(string str) {
		if (!str.length())
				return;
		int total = 10;

		for (int i = 1; i < str.length(); i++) {
				if (str[i] == str[i - 1])
						total += 5;
				else
						total += 10;
		}

		cout << total;
}