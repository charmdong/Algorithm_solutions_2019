#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

void solution(vector<int> v,int n, int k);

int main()
{
	int n, k, people;
	vector<int> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> people;
		v.push_back(people);
	}
	solution(v, n, k);
	return 0;
}

void solution(vector<int> v, int n, int k) {
	double avg;
	double sd; // 표준편차
	double total;
	vector<double> res;
	
	while (k <= n) {
		for (int i = 0; i < n - k + 1; i++) {
			total = 0;
			for (int j = i; j < i + k; j++)
				total += v[j];
			avg = total / k;

			total = 0;
			for (int j = i; j < i + k; j++)
				total += pow((v[j] - avg), 2);
			sd = sqrt(total / k);
			res.push_back(sd);
		}
		k++;
	}

	printf("%.11f\n", *min_element(res.begin(), res.end()));
}

/*
input :
5 3
1 2 3 4 5

10 3
1 4 1 5 9 2 6 5 3 5
output :
0.81649658092

0.94280904158

오차 범위 10-6승
*/
