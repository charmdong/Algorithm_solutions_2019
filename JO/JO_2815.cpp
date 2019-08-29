#include <iostream>
using namespace std;

void res();

int main()
{
		res();
		return 0;
}

void res() {
		int n, check=0;
		cin >> n;

		for (int i = sizeof(n)*8 - 1; i >= 0; i--) {
				if (n & (1 << i)) {
						check = i;
						break;
				}
		}
	
		for (int i = check; i >= 0; i--) {
				if (n & (1 << i)) cout << 1;
				else cout << 0;
		}
}