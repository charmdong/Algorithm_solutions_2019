/// �ֻ��� ������ 1

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
		case 1: firstCase(n, 0); break; // �ֻ����� N�� ���� ���� �� �ִ� ��� ���
		case 2: secondCase(n, 0); break; // �ֻ����� N�� ���� �ߺ��� �Ǵ� ��츦 �����ϰ� ���� �� �ִ� ��� ���
		case 3: thirdCase(n, 0); break; // �ֻ����� N�� ���� ��� �ٸ� ���� ���� �� �ִ� ��� ���
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