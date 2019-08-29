// 나무 재테크
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct tr {
	int y, x, age;
	tr(int y, int x, int a) :y(y), x(x), age(a) {}
};

int N, M, K;
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};
int map[11][11]; // 총 양분의 정보 - 처음에는 모두 5
vector<tr> tree;
int nutrient[11][11];// 로봇이 겨울에 추가하는 양분의 정보가 저장

bool cmp(const tr &a, const tr &b) {
	if (a.y == b.y && a.x == b.x)
		return a.age < b.age;
	else {
		if (a.x == b.x)
			return a.y < b.y;
		else
			return a.x < b.x;
	}
}
int solution();
bool isInMap(int y, int x);

int main()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			map[i][j] = 5;
	
	for (int i = 1; i <= N; i++) // 로봇이 추가할 양분의 정보 저장
		for (int j = 1; j <= N; j++)
			cin >> nutrient[i][j];

	for (int i = 0; i < M; i++) { // 나무 정보 추가
		int y, x, age;
		cin >> y >> x >> age;
		tree.push_back({y, x, age});
	}

	cout << solution() << endl;

	return 0;
}

int solution() {
	// K년 후의 결과를 체크해야하기 때문에
	while (K--) {
		sort(tree.begin(), tree.end(), cmp); // 나무 정렬 어린 순서대로
		
		vector<tr> alive;
		vector<tr> dead;
		vector<tr> five;
		vector<tr> birth;
		// spring
		for (auto &t : tree) {
			if (t.age <= map[t.y][t.x]) { // 양분 섭취 가능한 경우
				map[t.y][t.x] -= t.age; // 양분 섭취
				t.age++; // 나이 증가
				alive.push_back(t); // 살아남은 나무
			}
			else // 죽는 경우
				dead.push_back(t);
		}
		// summer
		for (auto t : dead) // 죽은 얘들 양분 처리 
			map[t.y][t.x] += t.age / 2;
		// fall
		for (auto t : alive) { // 살아 남은 나무들 중 번식 가능한 얘들 탐색
			if (t.age % 5 == 0)
				five.push_back(t);
		}
		for (auto t : five) { // 번식 가능한 나무 대상으로 번식할 곳 추가
			for (int d = 0; d < 8; d++) {
				int ny = t.y + dy[d];
				int nx = t.x + dx[d];

				if (isInMap(ny, nx))
					birth.push_back({ ny,nx,1 });
			}
		}

		tree.clear();
		for (auto t : alive)
			tree.push_back(t);
		for (auto t : birth)
			tree.push_back(t);
		// winter
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				map[i][j] += nutrient[i][j]; // 양분 추가
	}

	return tree.size();
}

bool isInMap(int y, int x) {
	if (y >= 1 && y <= N)
		if (x >= 1 && x <= N)
			return true;
	return false;
}