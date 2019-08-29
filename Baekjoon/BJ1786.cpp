#include <iostream>
#include <vector>
#include <string>
using namespace std;

void res(string, string);

int main()
{
	string str1, str2;
	getline(cin,str1);
	cin >> str2;
	res(str1, str2);
	return 0;
}

void res(string str1, string str2)
{
	int cnt=0,check;
	vector<int> pos;

	check = str1.find(str2, 0);
	while (check != string::npos) {
		pos.push_back(check+1);
		cnt++;
		check = str1.find(str2, check + str2.size());
	}
	
	cout << cnt << endl;
	if (pos.size())
		for (auto t : pos)
			cout << t << " ";
	else
		cout << 0;
}