#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> res(N);
	vector<double> fail(N + 1, 0), num(N+1,0);
	vector<int> stay(N+1,0), reach(N+1,0); // 실패율에 해당하는 스테이지 번호, 각 스테이지 도달자
	int cnt = 1;

	sort(stages.begin(), stages.end());
	for (int i = 0; i<stages.size(); i++) {
		if (stages[i] == N + 1) continue;
		if (i == stages.size() - 1) {
			stay[stages[i]] = cnt;
			break;
		}
		if (stages[i] != stages[i+1]) {// 각 스테이지별 머물고 있는 사람의 수
			stay[stages[i]] = cnt;
			cnt = 1;
		}
		else
			cnt++;
	}
	int tmp = stages.size();
	for (int i = 1; i <= N; i++) {
		tmp -= stay[i - 1];
		reach[i] = tmp;
	}

	for (int i = 1; i <= N; i++) {
		fail[i] = double(stay[i]) / reach[i];
		num[i] = i;
	}

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N- i; j++){
			if (fail[j] <fail[j + 1]){
				double tmp;
				int tmpnum;
				tmp = fail[j];
				fail[j] = fail[j + 1];
				fail[j + 1] = tmp;

				tmpnum = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmpnum;
			}
		}
	}
	for (int i = 1; i <= N; i++)
		res[i - 1] = num[i];

	return res;
}

int main()
{
	solution(5, { 2,1,2,6,2,4,3,3 });
	solution(4, { 4,4,4,4 });
	return 0;
}