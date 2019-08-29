#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n, int m);

int main()
{
	int n, m;
	cin >> n >> m;
	cout << solution(n, m);
	return 0;
}

int solution(int n, int m) {
	int total = 0;
	string s1="", s2="";

	for (int i = n; i <= m; i++) {
		string str = to_string(i);
		for (int k = 0; k < str.length(); k++) {
			s1 += str[k];
			s2 += str[str.length() - 1 - k];
		}
		if (s1 == s2)
			total++;
		s1 = s2 = "";
	}

	return total;
}