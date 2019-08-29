// 뱀
#include <iostream>
#include <vector>
using namespace std;

int N, K, L, ans;
int dir = 1; // 뱀 방향 : 최초에는 오른쪽
int map[101][101];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
vector<pair<int, int >> snake;
vector<pair<int, char>> rotation;
pair<int, int> tail;

void solution(int y = 1, int x = 1);
bool isInMap(int y, int x);
bool isBody(int y, int x);

int main()
{
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> K;
	
	for (int i = 0; i < K; i++) { // 사과 위치
		int ay, ax;
		cin >> ay >> ax;
		map[ay][ax] = 1;
	}

	cin >> L;
	rotation.assign(L, pair<int, char>());
	for (int i = 0; i < L; i++)
		cin >> rotation[i].first >> rotation[i].second;

	solution();
	cout << ans << endl;

	return 0;
}

void solution(int y, int x) {
	int hy = y;
	int hx = x;
	int beforeTime = 0;

	snake.push_back({ hy,hx }); // 대가리 위치 삽입.

	for (int i = 0; i <= L; i++) { // 방향 변환 횟수
		int s = (i==L) ? N : rotation[i].first - beforeTime;
		
		for(int j = 0; j < s; j++) {
			hy += dy[dir];
			hx += dx[dir];

			ans++; // 게임 시간 증가

			if (isInMap(hy, hx) && !isBody(hy, hx)) { // 다음 칸이 벽도 아니고 뱀 몸도 아닌 경우
				if (map[hy][hx] == 1) { // 사과가 있는 경우
					tail = snake[snake.size() - 1]; // 현재 꼬리 위치
					for (int k = snake.size() - 2; k >= 0; k--) // 몸통 움직이기
						snake[k + 1] = snake[k];
					snake.push_back(tail); // 꼬리 위치 갱신
					map[hy][hx] = 0; // 사과 처묵
				}
				else { // 사과 없는 경우
					for (int k = snake.size() - 2; k >= 0; k--) // 몸통 움직이기
						snake[k + 1] = snake[k];
				}
				snake[0] = { hy,hx }; // 머리 갱신
			}
			else return; // Game Over
		}
		beforeTime = rotation[i].first;
		dir = (rotation[i].second == 'D') ? (dir + 1) % 4 : (dir + 3) % 4; // 방향 변경
	}
}

bool isInMap(int y, int x) {
	if (y > 0 && y <= N)
		if (x > 0 && x <= N)
			return true;
	return false;
}

bool isBody(int y, int x) {
	for (auto t : snake)
		if (t.first == y && t.second == x)
			return true;
	return false;
}