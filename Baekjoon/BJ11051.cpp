#include <iostream>
#include <vector>
#define MOD 10007
#define MAX 1001
using namespace std;

int n, k;
int coef[MAX][MAX];
void solution();

int main()
{
	cin >> n >> k;
	solution();
	return 0;
}

void solution() {
	if (k == n || k == 0) {
		cout << 1 << endl;
		return;
	}
	
	coef[0][0] = 1;
	for (int i = 1; i <= n; i++) 
		coef[i][0] = coef[i][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			coef[i][j] = (coef[i-1][j-1] + coef[i-1][j])%MOD;
		}
	}

	cout << coef[n][k] << endl;
}