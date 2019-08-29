#include <iostream>
#include <string>
using namespace std;

int cnt[26];

int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		cnt[str[i] - 97]++;
	for (int i = 0; i < 26; i++)
		cout << cnt[i] << " ";
	return 0;
}