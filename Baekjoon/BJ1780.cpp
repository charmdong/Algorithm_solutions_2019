#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> cnt(3,0); // 0 : -1의 개수, 1 : 0의 개수, 2 : 1의 개수
vector<vector<int>> map;

void solution(int sy, int sx, int range);
int allSame(int sy, int sx, int div);

int main()
{
	cin >> n;
	map.assign(n, vector<int>(n,0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	solution(0,0,n);
	for (int t : cnt)
		cout << t << endl;
	return 0;
}

void solution(int sy, int sx ,int range) {
	int check = allSame(sy, sx, range);
	if (check != -2) { // 다 같은 숫자로 이루어진 경우
		cnt[check + 1]++;
		return;
	}

	int div = range / 3;
	if (div < 1) return;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solution(sy + i * div, sx + j * div, div);
		}
	}
}

int allSame(int sy, int sx, int div) {
	int check = map[sy][sx];
	for (int i = sy; i < sy + div; i++) {
		for (int j = sx; j < sx + div; j++) {
			if (map[i][j] != check)
				return -2;
		}
	}
	return check;
}