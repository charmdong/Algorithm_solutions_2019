/// 1146 : 선택 정렬

#include <iostream>
using namespace std;

void selectionSort(int *, int);
void printAry(int *, int);

int main()
{
		int len;
		int *ary;

		cin >> len;
		ary = new int[len];

		for (int i = 0; i < len; i++) {
				cin >> ary[i];
		}
		selectionSort(ary, len);

		delete[] ary;
		return 0;
}

void selectionSort(int *ary, int n) {
		for (int i = 0; i < n - 1; i++) {
				int minIndex = i;
				int min = ary[i];
				for (int k = i + 1; k < n; k++) {
						if (ary[k] < min) {
								min = ary[k];
								minIndex = k;
						}
				}
				if (minIndex != i) {
						int tmp = ary[minIndex];
						ary[minIndex] = ary[i];
						ary[i] = tmp;
				}
				printAry(ary, n);
		}
}

void printAry(int *ary, int n) {
		for (int i = 0; i < n; i++)
				cout << ary[i] << " ";
		cout << "\n";
}