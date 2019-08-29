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
	// �Ʒ��� �׽�Ʈ�� ����� ���� ���� �ڵ��Դϴ�.

	for (int i = 0; i< testAnswer.size(); i++)
	{
		cout << testAnswer[i] << " ";
	}
}
