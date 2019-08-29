#include <iostream>

#include <vector>
using namespace std;

vector<int> dp;
int solution(vector<int>);

int main()
{
	vector<int> v = { 0, 2, 0, 1, 3, 1, 2, 0, 1, 0, 2, 0 };
	dp.assign(v.size(), 0);
	cout << solution(v);

	return 0;
}

int solution(vector<int> v)
{
	int answer = 0;
	int left = 0;

	for (int i = 1; i <v.size(); i++) {
		if (v[i] == 0) {
			dp[i] = dp[i - 1];
			continue;
		}

		if (v[left] <= v[i]) {
			dp[i] = (i - left - 1)*v[left] - dp[i - 1];
			left = i;
		}
		else {

		}

	}
	
	return answer;
}