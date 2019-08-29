// ��
#include <iostream>
#include <vector>
using namespace std;

int N, K, L, ans;
int dir = 1; // �� ���� : ���ʿ��� ������
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
	
	for (int i = 0; i < K; i++) { // ��� ��ġ
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

	snake.push_back({ hy,hx }); // �밡�� ��ġ ����.

	for (int i = 0; i <= L; i++) { // ���� ��ȯ Ƚ��
		int s = (i==L) ? N : rotation[i].first - beforeTime;
		
		for(int j = 0; j < s; j++) {
			hy += dy[dir];
			hx += dx[dir];

			ans++; // ���� �ð� ����

			if (isInMap(hy, hx) && !isBody(hy, hx)) { // ���� ĭ�� ���� �ƴϰ� �� ���� �ƴ� ���
				if (map[hy][hx] == 1) { // ����� �ִ� ���
					tail = snake[snake.size() - 1]; // ���� ���� ��ġ
					for (int k = snake.size() - 2; k >= 0; k--) // ���� �����̱�
						snake[k + 1] = snake[k];
					snake.push_back(tail); // ���� ��ġ ����
					map[hy][hx] = 0; // ��� ó��
				}
				else { // ��� ���� ���
					for (int k = snake.size() - 2; k >= 0; k--) // ���� �����̱�
						snake[k + 1] = snake[k];
				}
				snake[0] = { hy,hx }; // �Ӹ� ����
			}
			else return; // Game Over
		}
		beforeTime = rotation[i].first;
		dir = (rotation[i].second == 'D') ? (dir + 1) % 4 : (dir + 3) % 4; // ���� ����
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