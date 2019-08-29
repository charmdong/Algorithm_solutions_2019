#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;

int solution(int no, vector<int> works);

int main()
{
	int no;
	cin >> no;
	cout << solution(no, { 4,3,3 });
	return 0;
}

int solution(int no, vector<int> works)
{
	int result=0;
	int index = 0;

	sort(works.begin(), works.end(), greater<int>());
	
	while (no--) {
		;
	}
		
	for (int val : works)
		result += val * val;

	return result;
}