#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector<int> setAlign(int n, long long cnt)
{
	vector<int> answer;
	for (int i = 1; i <= n; i++)
		answer.push_back(i);
	for (int i = 0; i< cnt - 1; i++)
		next_permutation(answer.begin(), answer.end());
	return answer;
}
int main()
{
	int testn = 3;
	long long testcnt = 5;
	vector<int> testAnswer = setAlign(testn, testcnt);
	// 아래는 테스트로 출력해 보기 위한 코드입니다.

	for (int i = 0; i< testAnswer.size(); i++)
	{
		cout << testAnswer[i] << " ";
	}
}
