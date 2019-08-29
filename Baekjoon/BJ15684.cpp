#include <iostream>
#include <algorithm>
using namespace std;

int ans=99999;
int N, M, H; // ���μ�, ���μ��� ����, ���μ��� ���� �� �ִ� ��ġ�� ����
int ladder[31][11];

bool check();
void dfs(int index=1, int cnt=0);

int main()
{
	int a, b;
	cin >> N >> M >> H;
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		ladder[a][b] = 1;
	}

	dfs();
	if (ans > 3) ans = -1;
	cout << ans << endl;

	return 0;
}

bool check() {
	for (int start = 1; start <= N; start++) {
		int end = start;
		for (int row = 1; row <= H; row++) {
			int left = ladder[row][end - 1]; // ���� ���μ����� ���� ��ٸ�
			int right = ladder[row][end]; // ���� ���μ����� ���� ��ٸ�

			if (left) end--;
			if (right) end++;
		}
		if (start != end)
			return false;
	}
	return true;
}

void dfs(int index, int cnt) {
	if (cnt > 3) return;
	
	if (check()) {
		ans = min(ans, cnt);
		return;
	}

	for (int i = 1; i < N; i++) { // i -> i+1�� ���� ���μ��� ����� �Ŵϱ� 
		for (int j = index; j <= H; j++) {// ���� ���μ��� ���ؼ� �����ؾ��ϱ� ������
			if (ladder[j][i] || ladder[j][i - 1] || ladder[j][i + 1]) // ���μ��� ���ӵ� �� ����.
				continue;

			ladder[j][i] = 1;
			dfs(j, cnt + 1);
			ladder[j][i] = 0;
		}
	}
}