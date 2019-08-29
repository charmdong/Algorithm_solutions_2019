#include <iostream>
#include <vector>
#include <string>
using namespace std;

void res(string str);

int main()
{
	vector<string> v;
	string tmp;
	int cnt;

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	
	for (int i = 0; i < v.size(); i++)
		res(v[i]);

	return 0;
}

void res(string str)
{
	int sum = 0;
	int score = 1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'O') {
			sum += score;
			score++;
		}
		else
			score = 1;
	}
	cout << sum << endl;
}
