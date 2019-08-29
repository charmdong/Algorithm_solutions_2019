#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<vector<int>> aryA, aryB, res;
void solution();

int main()
{
	cin >> n >> m;
	aryA.assign(n, vector<int>(m, 0));
	
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			cin >> aryA[i][j];

	cin >> m >> k;
	aryB.assign(m, vector<int>(k, 0));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			cin >> aryB[i][j];

	res.assign(n, vector<int>(k, 0));
	solution();
	return 0;
}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int tmp = 0;
			for (int w = 0; w < m; w++) 
				tmp += (aryA[i][w] * aryB[w][j]);
			res[i][j] = tmp;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}