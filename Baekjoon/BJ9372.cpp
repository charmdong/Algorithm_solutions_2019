// 상근이의 여행
#include <iostream>
using namespace std;

int test, n, m;

int main()
{
	int a, b;
	cin >> test;
	while (test--) {
		cin >> n >> m;
		
		for (int i = 0; i < m; i++) 
			cin >> a >> b;
		
		cout << n - 1 << endl;
	}

	return 0;
}