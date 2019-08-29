// Ȱ�ַ� �Ǽ�
#include <iostream>
#include <cstring>
using namespace std;

int N, X;
int map[20][20];
bool used[20][20];

int solution();

int main()
{
	ios::sync_with_stdio(false);

	int test;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		cin >> N >> X;
		for (int j = 0; j < N; j++) 
			for (int k = 0; k < N; k++) 
				cin >> map[j][k];
		
		cout << "#" << i << " " <<  solution() << endl;
		memset(used, false, sizeof(used));
	}

	return 0;
}

int solution() {
	int ans = 0;

	// ���ο� ���� ����
	for (int i = 0; i < N; i++) {
		bool check = true;
		for (int j = 0; j < N-1; j++) {
			// ���� ������ ���̰� ���� ���
			if (map[i][j] == map[i][j + 1]) continue;
			// ���� ������ �� ���� ���
			else if (map[i][j] - map[i][j + 1] == -1) {
				if (j - X + 1 >= 0) {
					for (int k = 1; k <= X; k++) {
						if (map[i][j+1-k] == map[i][j]) {
							if (used[i][j+1-k]) { // �̹� Ȱ�ַΰ� �Ǽ��Ǿ� �ִ� ���
								check = false;
								break;
							}
						}
						else {
							check = false;
							break;
						}
					}
				}
				else
					check = false;
			}
			// ���� ������ �� ���� ���
			else if (map[i][j] - map[i][j + 1] == 1) {
				if (j + X < N) { // �Ǽ� ������ ���
					for (int k = 1; k <= X; k++) {
						if (map[i][j + k] != map[i][j+1]) { // ������ �������� ���� ���
							check = false;
							break;
						}
					}
				}
				else
					check = false;
				if(check)
					for (int k = 1; k <= X; k++)
						used[i][j + k] = true;
			}
			// ���̰� ���� ���� ���
			else
				check = false;
			if (!check) break;
		}
		if (check) ans++;
	}
	memset(used, false, sizeof(used));
	// ���ο� ���� ����
	for (int j = 0; j < N; j++) {
		bool check = true;
		for (int i = 0; i < N-1; i++) {
			// ���� ������ ���̰� ���� ���
			if (map[i][j] == map[i+1][j]) continue;
			// ���� ������ �� ���� ���
			else if (map[i][j] - map[i+1][j] == -1) {
				if (i - X + 1 >= 0) {
					for (int k = 1; k <= X; k++) {
						if (map[i+1-k][j] == map[i][j]) {
							if (used[i+1-k][j]) { // �̹� Ȱ�ַΰ� �Ǽ��Ǿ� �ִ� ���
								check = false;
								break;
							}
						}
						else {
							check = false;
							break;
						}
					}
				}
				else
					check = false;
			}
			// ���� ������ �� ���� ���
			else if (map[i][j] - map[i+1][j] == 1) {
				if (i + X < N) { // �Ǽ� ������ ���
					for (int k = 1; k <= X; k++) {
						if (map[i+k][j] != map[i+1][j]) { // ������ �������� ���� ���
							check = false;
							break;
						}
					}
				}
				else
					check = false;
				if (check)
					for (int k = 1; k <= X; k++)
						used[i+k][j] = true;
			}
			// ���̰� ���� ���� ���
			else
				check = false;
			if (!check) break;
		}
		if (check) ans++;
	}

	return ans;
}