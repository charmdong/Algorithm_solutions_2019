#include <iostream>
#include <vector>
using namespace std;

int n,sum;
int solution(vector<int> ary);

int main()
{
	cin >> n;
	vector<int> ary(n);
	for (int i = 0; i < n; i++)
		cin >> ary[i];
	for (auto t : ary)
		sum += t;
	cout << solution(ary) << endl;
	return 0;
}

int solution(vector<int> ary) {
	int res = 0;
	

	for (int i = 0; i < n; i++) {
		int even = 0, odd = 0, tmpSum=sum;
		if ((tmpSum - ary[i]) % 2 == 1) continue;

		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			else if (j < i) {
				if (j % 2 == 0)
					odd += ary[j];
				else
					even += ary[j];
			}
			else {
				if (j % 2 == 1)
					odd += ary[j];
				else
					even += ary[j];
			}
		}
		if (odd == even) res++;
	}

	return res;
}