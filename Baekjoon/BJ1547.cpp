#include <iostream>
using namespace std;

int m;
int cup[4];
void swap(int a, int b);

int main()
{
	cin >> m;

	cup[1] = 1;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		swap(a, b);
	}
	for (int i = 1; i <= 3; i++) {
		if (cup[i] == 1) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}

void swap(int a, int b) {
	int tmp = cup[a];
	cup[a] = cup[b];
	cup[b] = tmp;
}