// ¿∑≥Ó¿Ã

#include <iostream>
#include <vector>
using namespace std;

void solution(vector<int> v);

int main()
{
	vector<int> v;
	int num;
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 4; k++) {
			cin >> num;
			v.push_back(num);
		}
		solution(v);
		v.assign(0,0);
	}
	return 0;
}

void solution(vector<int> v) {
	int total = 0;
	for (int i = 0; i < 4; i++) {
		if (v[i] == 0)
			total++;
	}

	if (total == 0)
		cout << "E\n";
	else
		printf("%c\n", 64 + total);
}