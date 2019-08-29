/// 가장 긴 회문의 길이 찾기

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPanlin(string str) {
		string front, back;
		front = str.substr(0, str.length() / 2);
		back = (str.length() % 2 == 0) ? str.substr(str.length() / 2) : str.substr(str.length() / 2 + 1);
		reverse(back.begin(), back.end());

		return front == back;
}

int solution(string str)
{
		int maxLen = 0;
		for (int i = 0; i < str.length(); i++) {
				string tmp;
				for (int k = 1; k <= str.length() - i; k++) {
						tmp = str.substr(i, k);
						//cout << tmp << endl;
						if (isPanlin(tmp)) {
								if (tmp.length() > maxLen)
										maxLen = tmp.length();
						}
				}
		}

		return maxLen;
}

int main()
{
		string str;
		cin >> str;
		cout << solution(str);
		return 0;
}