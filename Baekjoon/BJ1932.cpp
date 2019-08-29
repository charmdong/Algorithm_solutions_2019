/// Á¤¼ö »ï°¢Çü

#include <iostream>
#include <algorithm>
using namespace std;

int res[501][501], board[501][501], N, ans;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			cin >> board[i][j];

	res[1][1] = board[1][1];

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++)
			res[i][j] = max(res[i - 1][j], res[i - 1][j - 1]) + board[i][j];
	}

	for (int i = 2; i <= N; i++)
		for (int j = 1; j <= i; j++)
			if (res[i][j] > ans)
				ans = res[i][j];

	cout << ans << endl;

	return 0;
}