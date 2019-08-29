/// 2518 : 문자열 변환

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void edit(string& editStr, vector<char> beforeEdit, vector<char> afterEdit);

int main()
{
		char ch, before, after;
		int editCnt, strLen;
		cin >> editCnt;

		vector<char> beforeEdit, afterEdit;
		string editStr;
		for (int i = 0; i < editCnt; i++) {
				cin >> before >> after;
				beforeEdit.push_back(before);
				afterEdit.push_back(after);
		}
		cin >> strLen;
		for (int i = 0; i < strLen; i++) {
				cin >> ch;
				editStr += ch;
		}
		edit(editStr, beforeEdit, afterEdit);

		return 0;
}

void edit(string& editStr, vector<char> beforeEdit, vector<char> afterEdit) {
		for (int i = 0; i < editStr.length(); i++) {
				for (int k = 0; k < beforeEdit.size(); k++) {
						if (editStr[i] == beforeEdit[k]) {
								editStr[i] = afterEdit[k];
								break;
						}
				}
		}
		cout << editStr;
}