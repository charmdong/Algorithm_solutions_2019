// ��Ʈ�ι̳� - ���ó밡��
#include <iostream>
#include <vector>
#include <algorithm>
#define O 0 // origin
#define U 1 // up
#define D 2 // down
#define R 3 // right
#define L 4 // left
using namespace std;

int N, M, ans;
int map[500][500];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
vector<vector<vector<int>>> tetro; // ���� �����Ұ���.

int solution(int y, int x,int type);
bool isInMap(int y, int x);

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			for (int t = 0; t < 5; t++)
				ans = max(ans, solution(i,j,t)); // type ����

	cout << ans << endl;
	return 0;
}

int solution(int y ,int x, int type) {
	int res = 0;

	for (int i = 0; i < tetro[type].size(); i++) {
		int total = 0;
		for (int j = 0; j < tetro[type][i].size(); j++) {
			int ny = y + dy[tetro[type][i][j]];
			int nx = x + dx[tetro[type][i][j]];

			if (!isInMap(ny, nx)) break; // ������ ����� ��ȿ���� ����

			total += map[ny][nx];
		}
		res = max(res, total);
	}

	return res;
}

bool isInMap(int y, int x) {
	if (y > -1 && y < N)
		if (x > -1 && x < M)
			return true;
	return false;
}