#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100
using namespace std;

void checkWord(char*, int &);

int main()
{
	int num, cnt = 0;
	char str[MAX + 1];

	cin >> num;
	while (num--) {
		cin >> str;
		char* it = unique(str, str + strlen(str));
		*it = '\0';
		checkWord(str, cnt);
	}
	cout << cnt << endl;

	return 0;
}

void checkWord(char *str, int &cnt)
{
	for (int i = 0; i < strlen(str) - 1; i++) {
		for (int j = i + 1; j < strlen(str); j++)
			if (str[i] == str[j])
				return;
	}
	cnt++;
}