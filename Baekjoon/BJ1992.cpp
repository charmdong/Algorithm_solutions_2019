#include <iostream>
#include <vector>
#include <string>
using namespace std;

string ans="";
int n;
vector<vector<int>> map;
void solution(int sy, int sx, int range);
int allSame(int sy, int sx, int div);

int main()
{
	cin >> n;
	map.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &map[i][j]);

	solution(0,0, n);
	cout << ans << endl;
	return 0;
}

void solution(int sy, int sx, int range) {
	int check = allSame(sy, sx, range);
	if (check != -1) { // 모두 같은 수로 이루어진 경우
		ans += (check + '0');
		return;
	}

	int div = range / 2;
	if (div < 1) return;
	ans += "(";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			solution(sy + i * div, sx + j * div, div);
		}
	}
	ans += ")";
}

int allSame(int sy, int sx, int div) {
	int check = map[sy][sx];
	for (int i = sy; i < sy + div; i++)
		for (int j = sx; j < sx + div; j++)
			if (map[i][j] != check)
				return -1;
	return check;
}