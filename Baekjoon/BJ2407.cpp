#include <iostream>
using namespace std;

long long combination[101][101];
long long solution(int n, int m);

int main()
{
	int n, m;
	cin >> n >> m;
	cout << solution(n, m) << endl;
	return 0;
}

long long solution(int n, int m) {
	combination[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		combination[i][0] = combination[i][i] = 1;
		for (int j = 1; j <= m; j++) 
			combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
	}

	return combination[n][m];
}