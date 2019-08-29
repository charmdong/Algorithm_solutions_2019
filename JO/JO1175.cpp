/// 1175 : 주사위 던지기 2

#include <iostream>
using namespace std;

int sum, sumCheck = 0;
int allCase[7] = { 0 };
void diceResult(int n, int index);

int main()
{
		int num;
		cin >> num >> sum;
		diceResult(num, 0);
		return 0;
}

void diceResult(int n, int index) {
		for (int i = 1; i <= 6; i++) {
				allCase[index] = i;
				sumCheck += allCase[index];

				if (index < n - 1)
						diceResult(n, index + 1);
				else {
						if (sum == sumCheck) {
								for (int i = 0; i < n; i++)
										cout << allCase[i] << " ";
								cout << "\n";
						}
				}
				sumCheck -= allCase[index];
		}
}