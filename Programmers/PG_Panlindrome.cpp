/**
 * PG : 가장 긴 팰린드롬
 * type : practice
 */ 

#include <iostream>
#include <string>
using namespace std;

bool isPanlin(string str);
int solution(string s);

bool isPanlin(string str) {
	int len = str.length();

	for(int index = 0; index < len / 2; index++) {
		if(str[index] != str[len - index - 1]) {
			return false;
		}
	}
	return true;
}

int solution(string str) {
	int answer = 1;
	int len = str.length();

	for(int i = len; i > 0; i--) {
		for(int j = 0; j <= len - i; j++) {
			string tmpStr = str.substr(j, i);
			if(isPanlin(tmpStr)) {
				return tmpStr.length();
			}
		}
	}

	return answer;
}

int main()
{
	cout << solution("abcdcba") << endl;
	cout << solution("abacde") << endl;
	return 0;
}