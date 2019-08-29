// 핀볼 게임
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[100][100];
int dy[5] = {0,-1,1,0,0};
int dx[5] = { 0,0,0,-1,1 };

vector<vector<pair<int, int>>> warm; // index : warmNum-6;

int solution(int sy, int sx, int direct);
bool isInMap(int y, int x);

int main()
{
	int test, ans;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		ans = 0;
		warm.assign(5, vector<pair<int, int>>());
		cin >> N;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> map[j][k];
				if (map[j][k] >= 6)
					warm[map[j][k] - 6].push_back({ j,k });
			}
		}

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (map[j][k] == 0) {
					for (int d = 1; d <= 4; d++)
						ans = max(ans, solution(j, k, d));
				}
			}
		}
		cout << "#" << i << " " << ans << endl;
	}
	return 0;
}

int solution(int sy, int sx, int direct) {
	int score = 0;
	int ny = sy;
	int nx = sx;
	int nd = direct;

	while (true) {
		ny += dy[nd];
		nx += dx[nd];

		if (!isInMap(ny, nx)) { // 벽 부딪혔을 때
			nd = (nd % 2 == 0) ? nd - 1 : nd + 1;
			score++;
			continue;
		}

		if (ny == sy && nx == sx) return score; // 시작점으로 돌아온 경우

		switch (map[ny][nx]) {
		case -1: return score; // 블랙홀 만난 경우
		case 0: continue;
		case 1: 
			if (nd == 2) nd = 4;
			else if (nd == 3) nd = 1;
			else
				nd = (nd % 2 == 0) ? nd - 1 : nd + 1;
			score++;
			break;
		case 2: 
			if (nd == 1) nd = 4;
			else if (nd == 3) nd = 2;
			else
				nd = (nd % 2 == 0) ? nd - 1 : nd + 1;
			score++;
			break;
		case 3: 
			if (nd == 1) nd = 3;
			else if (nd == 4) nd = 2;
			else
				nd = (nd % 2 == 0) ? nd - 1 : nd + 1;
			score++;
			break;
		case 4: 
			if (nd == 2) nd = 3;
			else if (nd == 4) nd = 1;
			else
				nd = (nd % 2 == 0) ? nd - 1 : nd + 1;
			score++;
			break;
		case 5: // 좌표 변경해줄 필요는 없음. 방향만 반대로 변경
			nd = (nd % 2 == 0) ? nd - 1 : nd + 1;
			score++;
			break;
		default: 
			int index = map[ny][nx] - 6;
			if (warm[index][0] == make_pair(ny, nx)) {
				ny = warm[index][1].first;
				nx = warm[index][1].second;
			}
			else {
				ny = warm[index][0].first;
				nx = warm[index][0].second;
			}
		}
	}
}

bool isInMap(int y, int x) {
	if (y > -1 && y < N)
		if (x > -1 && x < N)
			return true;
	return false;
}