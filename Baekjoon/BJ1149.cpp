/// 동적 계획법 - RGB 거리

#include <iostream>
#include <algorithm>
using namespace std;

int rgb[1001][3] = { 0 };
int res[1001][3] = { 0 };
int solution(int num);

int main()
{
	int num;
	cin >> num;

	for (int i = 1; i <= num; i++) {
		for (int j = 0; j <3; j++)
			cin >> rgb[i][j];
	}
	
	cout << solution(num) << endl;

	return 0;
}

int solution(int num) {
	for (int i = 1; i <= num; i++) {
		res[i][0] = min(res[i - 1][1], res[i - 1][2]) + rgb[i][0];
		res[i][1] = min(res[i - 1][0], res[i - 1][2]) + rgb[i][1];
		res[i][2] = min(res[i - 1][0], res[i - 1][1]) + rgb[i][2];
	}
	// 3가지 경우에 대해서 모두 비교를 해야한다.
	return min(min(res[num][0], res[num][1]), res[num][2]);
}