#include <iostream>
#define MAX 20
using namespace std;

int n, s, ans;
int ary[MAX];
void solution(int index=0, int sum=0);

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> ary[i];
	
	for (int i = 0; i < n; i++)
		solution(i, ary[i]);

	cout << ans << endl;
	return 0;
}

void solution(int index, int sum) {
	if (index > n)
		return;
	
	if (sum == s)
		ans++;

	for (int i = index + 1; i < n; i++)
		solution(i, sum + ary[i]);
}