#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
string ans="";
char num[3] = { 1,2,3 };

void solution(string str,  int len = 0);
bool isGood(string str);

int main()
{
	cin >> n;
	solution("", 0);
	cout << ans << endl;
	return 0;
}

void solution(string str, int len) {
	if (len == n) {
		// 좋은 순열인지 확인
		if (isGood(str))
			ans = (ans < str) ? ans : str;
		return;
	}

	for (int i = 0; i < 3; i++) {
		string tmp = str;
		str += num[i]; 
		solution(str, len + 1);
		str = tmp;
	}
}

bool isGood(string str) {
	for (int i = 0; i < n - 1; i++) {
		string sub1, sub2;
		for (int len = 1; len < (n-i)/2; len++) {
			sub1 = str.substr(i, len);
			sub2 = str.substr(i + len, len);
			if (sub1 == sub2)
				return false;
		}
	}

	return true;
}