#include <iostream>
#include <stack>
#define MAX 100000
using namespace std;

int n;
int ary[MAX];
int solution();

int main()
{
	while (1) {
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
			cin >> ary[i];
		cout << solution() << endl;
	}
	return 0;
}

int solution() {
	stack<int> s;
	


}