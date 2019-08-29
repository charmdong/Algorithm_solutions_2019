// µå·¡°ï Ä¿ºê
#include <iostream>
#include <vector>
using namespace std;

int N;
int dy[4] = { 0 ,-1 , 0 ,1 };
int dx[4] = { 1,0,-1,0 };
int map[101][101];
vector<pair<int, int>> dragon;
bool check(int y, int x);
int answer();
void makeDragon(int y, int x, int d, int g);

int main()
{
	cin >> N;
	int y, x, d, g;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		makeDragon(y, x, d, g);
		dragon.clear();
	}
	cout << answer() << endl;

	return 0;
}

void makeDragon(int y, int x, int d, int g) {
	// 0 Generation
	dragon.push_back({ y,x });
	dragon.push_back({ y + dy[d], x + dx[d] });

	// 1~N generation
	for (int i = 0; i < g; i++) {
		int len = dragon.size();
		int ry = dragon[len - 1].first;
		int rx = dragon[len - 1].second;
		for (int j = len - 2; j >= 0; j--) {
			int y = dragon[j].first;
			int x = dragon[j].second;

			if (y > ry && x == rx)
				dragon.push_back({ ry, x - y + ry });
			else if (y == ry && x < rx)
				dragon.push_back({ y - rx + x, rx });
			else if (x == rx && y < ry)
				dragon.push_back({ ry, x + ry - y });
			else if (y == ry && x > rx)
				dragon.push_back({ y + x - rx, rx });
			else if (x > rx && y > ry)
				dragon.push_back({ ry + (x - rx), rx - (y - ry) });
			else if (x < rx && y > ry)
				dragon.push_back({ ry - (rx - x), rx - (y - ry) });
			else if (x < rx && y < ry)
				dragon.push_back({ ry - (rx - x), rx + (ry - y) });
			else
				dragon.push_back({ ry + (x - rx), rx + (ry - y) });
		}
	}

	for (auto t : dragon)
		map[t.first][t.second] = 1;
}

int answer() {
	int ans = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (check(i, j))
				ans++;
	return ans;
}

bool check(int y, int x) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (map[y + i][x + j] != 1)
				return false;
	return true;
}