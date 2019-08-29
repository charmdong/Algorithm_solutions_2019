// ���� - �����ϴ� ����� �ٽ� �����غ���.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M, ans=987654321;
int map[8][8];
int dy[4] = { -1,0,1,0 };
int dx[4] = {0,1,0,-1 };
vector<pair<int, int>> pos;
vector<int> type;

void change(int y, int x, int type, int dir);
void dfs(int index=0);
void copy(int(*)[8], bool recover=false);
bool isInMap(int y, int x);
int getNum();

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6) {
				pos.push_back({ i,j });
				type.push_back(map[i][j]);
			}
		}
	}

	dfs();
	cout << ans << endl;
	return 0;
}

void change(int y, int x, int type, int dir) {
	int ny = y;
	int nx = x;
	
	if (type == 1) {
		while (true) {
			ny += dy[dir];
			nx += dx[dir];

			if (isInMap(ny, nx)) { // ���� ��ǥ�� �� �ȿ� �����ϴ� ���
				if (map[ny][nx] == 0) // ���� ������ �ڸ�
					map[ny][nx] = -1;
				else if (map[ny][nx] == -1 || map[ny][nx] != 6) // �̹� ���ð� ����� �ڸ��ų� CCTV�� ���
					continue;
				else // ���� ���
					break;
			}
			else break;
		}
	}
	else if (type == 2) { // dir, �ݴ� ����
		for (int i = 0; i <2; i++) { // i = 0 : ������ i = 1 : ������
			ny = y, nx = x; // cctv ��ġ�� ����
			while (true) {
				ny += dy[(dir + 2*i) % 4];
				nx += dx[(dir + 2*i) % 4];

				if (isInMap(ny, nx)) { // ���� ��ǥ�� �� �ȿ� �����ϴ� ���
					if (map[ny][nx] == 0) // ���� ������ �ڸ�
						map[ny][nx] = -1;
					else if (map[ny][nx] == -1 || map[ny][nx] != 6) // �̹� ���ð� ����� �ڸ�
						continue;
					else // ���̰ų� cctv�� ���
						break;
				}
				else break;
			}
		}
	}
	else { // 3, 4, 5Ÿ���� ī�޶��� ���
		for (int i = 0; i < type-1; i++) {
			ny = y, nx = x;
			while (true) {
				ny += dy[(dir + i) % 4];
				nx += dx[(dir + i) % 4];

				if (isInMap(ny, nx)) { // ���� ��ǥ�� �� �ȿ� �����ϴ� ���
					if (map[ny][nx] == 0) // ���� ������ �ڸ�
						map[ny][nx] = -1;
					else if (map[ny][nx] == -1 || map[ny][nx] != 6) // �̹� ���ð� ����� �ڸ�
						continue;
					else // ���̰ų� cctv�� ���
						break;
				}
				else break;
			}
		}
	}
}

void copy(int(*cp)[8], bool recover) {
	if (!recover) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cp[i][j] = map[i][j];
	}
	else
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				map[i][j] = cp[i][j];
}

void dfs(int index) {
	if (index == pos.size()) {
		ans = min(ans, getNum());
		return;
	}

	int limit;
	if (type[index] != 2 && type[index] != 5) limit = 4;
	else if (type[index] == 2) limit = 2;
	else limit = 1;
	
	int copied[8][8];

	for (int d = 0; d < limit; d++) {
		copy(copied);
		change(pos[index].first, pos[index].second, type[index], d);
		dfs(index + 1);
		copy(copied, true);
	}
}

bool isInMap(int y, int x) {
	if (y > -1 && y < N)
		if (x > -1 && x < M)
			return true;
	return false;
}

int getNum() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 0) // �簢����
				cnt++;
	return cnt;
}