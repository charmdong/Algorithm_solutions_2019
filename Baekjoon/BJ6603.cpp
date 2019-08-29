#include <iostream>
#define MAX 13
#define LOT 6
using namespace std;

int k;
int ary[MAX];
int lotto[MAX];

void DFS(int start, int index);

int main()
{
	while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++)
			cin >> lotto[i];
		DFS(0, 0);
		cout << endl;
	}
	return 0;
}

void DFS(int start, int index) {
	if (index == LOT) {
		for (int i = 0; i < LOT; i++)
			cout << ary[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = start; i < k; i++) {
		ary[index] = lotto[i];
		DFS(i + 1, index + 1);
	}
}