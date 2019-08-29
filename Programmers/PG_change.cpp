#include<iostream>
#include<vector>
using namespace std;

int change(int total, vector<int> coin);

int main()
{
		int total = 5;
		vector<int > test{ 1,2,5 };

		// 아래는 테스트로 출력해 보기 위한 코드입니다.
		cout << change(total, test);
		return 0;
}

int change(int total, vector<int> coin)
{
		int answer = 0;

		return answer;
}