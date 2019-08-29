/// 크로아티아 알파벳

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> croatia = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
void solution(string str);

int main()
{
		string str;
		cin >> str;
		solution(str);
		return 0;
}

void solution(string str) {
		int total = 0;

		for (int i = 0; i < croatia.size(); i++) {
				string check = croatia[i];
				while (str.find(check, 0) != string::npos) {
						str.replace(str.find(check, 0), check.length(), "1");
						total++;
				}
		}
		
		for (int i = 0; i < str.length(); i++)
				if (str[i] != '1') total++;

		cout << total;
}