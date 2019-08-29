#include <iostream>
#include <algorithm>
#define MAX 11
using namespace std;

int n;
int numbers[MAX];
int p, s, d, m; // the number of each operator.
int big = -1000000000;
int small = 1000000000;

void solution(int index, int p, int s, int m, int d, int total);

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	cin >> p >> s >> m >> d;
	solution(1, 0, 0, 0, 0, numbers[0]);
	cout << big << endl << small << endl;
	return 0;
}

void solution(int index, int plus, int sub, int mul, int div, int total) {
	if (index == n) {
		big = max(big, total);
		small = min(small, total);
		return;
	}

	if (plus < p)
		solution(index + 1, plus + 1, sub, mul, div, total + numbers[index]);
	if (sub < s)
		solution(index + 1, plus, sub + 1, mul, div, total - numbers[index]);
	if (mul < m)
		solution(index + 1, plus, sub, mul + 1, div, total * numbers[index]);
	if (div < d)
		solution(index + 1, plus, sub, mul,  div + 1, total / numbers[index]);
}