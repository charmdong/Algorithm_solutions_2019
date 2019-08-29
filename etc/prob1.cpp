#include <iostream>
#include <string>
using namespace std;

int cnt[26];
string solution(string s);

int main() 
{
	string str;
	cin >> str;
	cout << solution(str) << endl;
	return 0;
}

string solution(string s)
{
	string answer;

	// �ҹ��ڷ� �����
	for (int i = 0; i < s.length(); i++) {
		if (s[i] < 97)
			s[i] += 32;
		cnt[s[i] - 97]++;
	}

	// ���� ���� ����� ���ĺ� ���ϱ�
	int max = 0;
	for (int i = 0; i < 26; i++) {
		max = (max < cnt[i]) ? cnt[i] : max;
	}

	for (int i = 0; i < 26; i++) {
		if (cnt[i] == max)
			answer += (i + 97);
	}
	
	return answer;
}

