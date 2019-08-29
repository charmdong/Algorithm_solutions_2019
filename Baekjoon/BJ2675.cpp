#include <iostream>
#include <vector>
#include <cstring>
#define MAX 20
using namespace std;

void prn(vector<char*> v, vector<int> numAry, int num);

int main()
{
	int cnt, subNum;
	vector<int> ary;
	vector<char*> v;
	char *str;

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		str = new char[MAX + 1];
		cin >> subNum;
		ary.push_back(subNum);
		cin >> str;
		v.push_back(str);
	}
	
	prn(v, ary, cnt);
	for (int i = 0; i < cnt; i++)
		delete[] v[i];
	
	return 0;
}

void prn(vector<char*> v, vector<int> numAry, int num)
{
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < strlen(v[i]); j++) {
			for (int k = 0; k < numAry[i]; k++)
				cout << v[i][j];
		}
		cout << endl;
	}
}