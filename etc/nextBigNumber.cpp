#include <iostream>
using namespace std;

int nextBigNumber(int n);
int checkCnt(int n);

int main()
{
		int n = 78;
		cout << nextBigNumber(n);

		return 0;
}

int checkCnt(int n) {
		int bCnt = 0;

		for (int i = 31; i >= 0; i--) {
				if (n & (1 << i))
						bCnt++;
		}
		return bCnt;
}

int nextBigNumber(int n)
{
		int i = 1;
		while (1) {
				if (checkCnt(n) == checkCnt(n + i))
						return n + i;
				i++;
		}
}