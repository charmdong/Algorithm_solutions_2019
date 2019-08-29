/// 1620 : 전화번호 속의 암호

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check = true;
void parsing(string phone, vector<string>& parse);
void encodeResult(vector<string> parsing, int add, int dummy);

int main()
{
		string phone;
		vector<string> parse;
		int first, second;
		cin >> phone >> first >> second;
		parsing(phone, parse);
		encodeResult(parse, first, second);
		return 0;
}

void parsing(string phone, vector<string>& parse) {
		int index;
		index = phone.find('-');
		while (index != string::npos) {
				parse.push_back(phone.substr(0, index));
				phone = phone.substr(index + 1);
				index = phone.find('-');
		}
		parse.push_back(phone);

		for (int i = 0; i < parse.size(); i++) {
				string tmp;
				if (parse[i].length() < 4) {
						for (int k = 0; k < 4 - parse[i].length(); k++)
								tmp += "0";
				}
				else if (parse[i].length() > 4) {
						check = false;
						return;
				}
				parse[i] = tmp + parse[i];
		}
}

void encodeResult(vector<string> parsing, int add, int dummy) {
		if (!check || dummy> parsing.size()) {
				cout << "INPUT ERROR!\n";
				return;
		}

		string res, dummyStr;
		dummyStr = parsing[dummy - 1];
		for (int i = 0; i < 4; i++) {
				int n = dummyStr[i]-'0';
				if (add + n >= 10)
						res += (add + n - 10) + '0';
				else
						res += (add + n) + '0';
		}

		cout << res;
}