#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<string> v;

bool cmp(string &a, string &b) {
	if (a.length() < b.length())
		return true;
	else if (a.length() > b.length())
		return false;
	else {
		if (a < b)
			return true;
		else
			return false;
	}
}

int main()
{
	cin >> n;
	
	v.assign(n, "");
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end(), cmp);
	string check=v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == check)
			continue;
		else {
			cout << check << endl;
			check = v[i];
		}
	}
	cout << check << endl;

	return 0;
}