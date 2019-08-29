/// 최솟값 만들기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>, vector<int>);

int main()
{
	cout << solution({ 1,4,2 }, { 5,4,4 });
	return 0;
}

int solution(vector<int> a, vector<int> b) {
	int res = 0;

	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	for (int i = 0; i < a.size(); i++)
		res += a[i] * b[i];

	return res;
}