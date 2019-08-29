#include <iostream>
#include <algorithm>
#define MAX 50
using namespace std;

struct person {
	int h, w;
} p[MAX];

int n;
int ans[MAX];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> p[i].w >> p[i].h;

	for (int i = 0; i < n; i++) {
		ans[i] = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (p[j].w > p[i].w && p[j].h > p[i].h)
				ans[i]++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}