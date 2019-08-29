// ���� ����ũ
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
int map[11][11]; // �� ����� ���� - ó������ ��� 5
vector<tr> tree;
int nutrient[11][11];// �κ��� �ܿ￡ �߰��ϴ� ����� ������ ����

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
	
	for (int i = 1; i <= N; i++) // �κ��� �߰��� ����� ���� ����
		for (int j = 1; j <= N; j++)
			cin >> nutrient[i][j];

	for (int i = 0; i < M; i++) { // ���� ���� �߰�
		int y, x, age;
		cin >> y >> x >> age;
		tree.push_back({y, x, age});
	}

	cout << solution() << endl;

	return 0;
}

int solution() {
	// K�� ���� ����� üũ�ؾ��ϱ� ������
	while (K--) {
		sort(tree.begin(), tree.end(), cmp); // ���� ���� � �������
		
		vector<tr> alive;
		vector<tr> dead;
		vector<tr> five;
		vector<tr> birth;
		// spring
		for (auto &t : tree) {
			if (t.age <= map[t.y][t.x]) { // ��� ���� ������ ���
				map[t.y][t.x] -= t.age; // ��� ����
				t.age++; // ���� ����
				alive.push_back(t); // ��Ƴ��� ����
			}
			else // �״� ���
				dead.push_back(t);
		}
		// summer
		for (auto t : dead) // ���� ��� ��� ó�� 
			map[t.y][t.x] += t.age / 2;
		// fall
		for (auto t : alive) { // ��� ���� ������ �� ���� ������ ��� Ž��
			if (t.age % 5 == 0)
				five.push_back(t);
		}
		for (auto t : five) { // ���� ������ ���� ������� ������ �� �߰�
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
				map[i][j] += nutrient[i][j]; // ��� �߰�
	}

	return tree.size();
}

bool isInMap(int y, int x) {
	if (y >= 1 && y <= N)
		if (x >= 1 && x <= N)
			return true;
	return false;
}