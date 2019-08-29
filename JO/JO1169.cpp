/// 주사위 던지기 1

#include <iostream>
#include <vector>
using namespace std;

int allCase[5] = { 0 };
bool check[6] = { 0 };
vector<int> charCnt(6,0);
vector<vector<int>> total;

void printResult(int n, int type);
void firstCase(int n, int index);
void secondCase(int n, int index);
void thirdCase(int n, int index);

int main()
{
		int n, type;
		cin >> n >> type;
		printResult(n, type);
		return 0;
}

void printResult(int n, int type) {
		switch (type) {
		case 1: firstCase(n, 0); break; // 주사위를 N번 던져 나올 수 있는 모든 경우
		case 2: secondCase(n, 0); break; // 주사위를 N번 던져 중복이 되는 경우를 제외하고 나올 수 있는 모든 경우
		case 3: thirdCase(n, 0); break; // 주사위를 N번 던져 모두 다른 수가 나올 수 있는 모든 경우
		default: break;
		}
}

void firstCase(int n, int index) {
		for (int i = 1; i <= 6; i++) {
				allCase[index] = i;
				if (index < n - 1)
						firstCase(n, index + 1);
				else {
						for (int i = 0; i < n; i++)
								cout << allCase[i] << " ";
						cout << "\n";
				}
		}
}

void secondCase(int n, int index) {
		for (int i = 1; i <= 6; i++) {
				bool isExist = false;
				allCase[index] = i;
				charCnt[i-1]++;

				if (index < n - 1)
						secondCase(n, index + 1);
				else {
						for (int i = 0; i < total.size(); i++) {
								if (total[i] == charCnt) {
										isExist = true;
										break;
								}
						}

						if (!isExist) {
								total.push_back(charCnt);
								for (int i = 0; i < n; i++)
										cout << allCase[i] << " ";
								cout << "\n";
						}
				}
				charCnt[i-1]--;
		}
}

void thirdCase(int n, int index) {
		for (int i = 1; i <= 6; i++) {
				if (check[i-1]) continue;
				allCase[index] = i;
				check[i-1] = true;
				
				if (index < n - 1) 
						thirdCase(n, index + 1);
				else {
						for (int i = 0; i < n; i++)
								cout << allCase[i] << " ";
						cout << "\n";
				}
				check[i-1] = false;
		}
}