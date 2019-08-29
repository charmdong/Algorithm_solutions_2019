/// 올바른 괄호

#include <iostream>
#include <string>
using namespace std;

bool solution(string str);

int main()
{
	cout << solution("()()") << "\n";
	return 0;
}

bool solution(string str) {
	int check = 0;

	for (int i = 0; i < str.length(); i++) {
		str[i] == '(' ? check++ : check--;
		if (check < 0) return false;
	}

	return check == 0;
}