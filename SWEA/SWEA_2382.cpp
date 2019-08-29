// 미생물 격리
#include <iostream>
#include <vector>
using namespace std;

struct micro {
	int y, x;
	int amount;
	int direct;
	micro(int y = 0, int x =0, int a = 0, int d = 0) :y(y),x(x), amount(a), direct(d) {}
};

int n,m,k;
int dy[5] = {0,-1,1,0,0};
int dx[5] = {0,0,0,-1,1};
vector<micro> mc;
//vector<int> map[100][100]; // 각 좌표에 위치한 군집의 번호를 저장할 변수

bool isInDeath(int y, int x);
void solution();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int test;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		int ans = 0;
		cin >> n >> m >> k;
		mc.assign(k, micro());
		
		for (int j = 0; j < k; j++)
			cin >> mc[j].y >> mc[j].x >> mc[j].amount >> mc[j].direct;

		while (m--) {
			solution();
		}
		for (auto t : mc)
			ans += t.amount;

		cout << "#" << i << " " << ans << endl;
	}

	return 0;
}

void solution() { // 1시간 움직임에 대한 군집들의 위치 변화
	for (auto &t : mc) { // 해당 방향으로 움직이기
		if (t.amount == 0) continue; // 군집이 죽은 경우
		t.y += dy[t.direct];
		t.x += dx[t.direct];
	}

	for (int i = 0; i < mc.size(); i++) {
		if (mc[i].amount != 0) { // 군집이 살아 있는 경우
			if (isInDeath(mc[i].y, mc[i].x)) {  // 약물 친 곳에 위치했다면
				if ((mc[i].amount /= 2) == 0) continue; // 미생물이 다 뒤졌다면 패스
				mc[i].direct = (mc[i].direct % 2 == 0) ? mc[i].direct - 1 : mc[i].direct + 1; // 방향 변경
				continue; // 약물 친 곳에서는 군집이 만날 일이 없음
			}

			// 군집 겹칠 수 있는 경우
			int maxIndex = i;
			int na = mc[i].amount; // 미생물 합

			for (int j = 0; j < mc.size(); j++) { // 군집이 겹치는 경우 탐색
				if (mc[j].amount == 0 || i==j) continue; // 군집이 죽은 경우
				if (mc[i].y == mc[j].y && mc[i].x == mc[j].x) { // 같은 좌표에 위치한다면
					na += mc[j].amount;
					if (mc[maxIndex].amount < mc[j].amount) {
						mc[maxIndex].amount = 0;
						maxIndex = j;
					}
					else
						mc[j].amount = 0;
				}
			}
			mc[maxIndex].amount = na; // 겹치는 얘들 중 가장 큰 군집의 미생물 수 갱신
		}
	}
}

bool isInDeath(int y, int x) {
	return (y == 0 || y == n - 1 || x == 0 || x == n - 1);
}