#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<int> ary);

int main() {

	return 0;
}

bool solution(vector<int> ary) {
	vector<int> res(ary.size() + 1, 0);

	for (int i = 0; i < ary.size(); i++) {
		res[ary[i]]++;
	}

	for (int i = 1; i < res.size(); i++)
		if (res[i] == 0)
			return false;
	return true;
}