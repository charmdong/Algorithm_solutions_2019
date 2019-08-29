// 활주로 건설
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

	// 가로에 대해 조사
	for (int i = 0; i < N; i++) {
		bool check = true;
		for (int j = 0; j < N-1; j++) {
			// 다음 지형의 높이가 같은 경우
			if (map[i][j] == map[i][j + 1]) continue;
			// 다음 지형이 더 높은 경우
			else if (map[i][j] - map[i][j + 1] == -1) {
				if (j - X + 1 >= 0) {
					for (int k = 1; k <= X; k++) {
						if (map[i][j+1-k] == map[i][j]) {
							if (used[i][j+1-k]) { // 이미 활주로가 건설되어 있는 경우
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
			// 다음 지형이 더 낮은 경우
			else if (map[i][j] - map[i][j + 1] == 1) {
				if (j + X < N) { // 건설 가능한 경우
					for (int k = 1; k <= X; k++) {
						if (map[i][j + k] != map[i][j+1]) { // 지형이 일정하지 않은 경우
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
			// 차이가 많이 나는 경우
			else
				check = false;
			if (!check) break;
		}
		if (check) ans++;
	}
	memset(used, false, sizeof(used));
	// 세로에 대해 조사
	for (int j = 0; j < N; j++) {
		bool check = true;
		for (int i = 0; i < N-1; i++) {
			// 다음 지형의 높이가 같은 경우
			if (map[i][j] == map[i+1][j]) continue;
			// 다음 지형이 더 높은 경우
			else if (map[i][j] - map[i+1][j] == -1) {
				if (i - X + 1 >= 0) {
					for (int k = 1; k <= X; k++) {
						if (map[i+1-k][j] == map[i][j]) {
							if (used[i+1-k][j]) { // 이미 활주로가 건설되어 있는 경우
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
			// 다음 지형이 더 낮은 경우
			else if (map[i][j] - map[i+1][j] == 1) {
				if (i + X < N) { // 건설 가능한 경우
					for (int k = 1; k <= X; k++) {
						if (map[i+k][j] != map[i+1][j]) { // 지형이 일정하지 않은 경우
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
			// 차이가 많이 나는 경우
			else
				check = false;
			if (!check) break;
		}
		if (check) ans++;
	}

	return ans;
}