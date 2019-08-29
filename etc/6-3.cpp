/// 알고리즘 문제해결전략 6-3 : 소풍

#include <iostream>
#include <vector>
using namespace std;

int n;
bool areFriends[10][10];

int countPairings(bool *taken);
void initFriends();
void printFriends();
void printTaken(bool *taken);

int main()
{
		bool taken[10] = { false };
		
		int cnt;
		cin >> cnt;
		while (cnt--) {
				cin >> n;
				int pair;
				cin >> pair;
				for (int i = 0; i < pair; i++) {
						int x,y;
						cin >> x >> y;
						areFriends[x][y] = areFriends[y][x] = true;
				}
				cout << countPairings(taken) << endl;
				initFriends();
		}

		return 0;
}

int countPairings(bool *taken) {
		int firstFree = -1;
		for (int i = 0; i < n; i++) {
				if (!taken[i]) {
						firstFree = i;
						break;
				}
		}

		printTaken(taken);
		//모든 학생이 짝을 찾은 경우에 해당 한 가지 방법을 찾았으므로 종료한다.
		if (firstFree == -1) return 1;
		int ret = 0;

		for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
				if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
						taken[firstFree] = taken[pairWith] = true;
						ret += countPairings(taken);
						taken[firstFree] = taken[pairWith] = false;
				}
		}
		return ret;
}

void printFriends() {
		cout << endl;
		for (int i = 0; i < n; i++) {
				for (int k = 0; k < n; k++)
						cout << areFriends[i][k] << " ";
				cout << endl;
		}
}

void printTaken(bool *taken) {
		cout << endl;
		for (int i = 0; i < n; i++)
				cout << taken[i] << " ";
		cout << endl;
}

void initFriends() {
		for (int i = 0; i < n; i++) {
				for (int k = 0; k < n; k++)
						areFriends[i][k] = false;
		}
}