#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct member {
	int age;
	string name;
};

bool cmp(member &a, member &b) {
	if (a.age < b.age) return true;
	else return false;
}

int main()
{
	int n, age;
	string name;
	vector<member> v;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> age;
		cin >> name;
		v.push_back({ age, name });
	}
	sort(v.begin(), v.end(), cmp);
	for (auto m : v)
		cout << m.age << " " << m.name << endl;
	return 0;
}