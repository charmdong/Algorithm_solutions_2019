/// 소수의 함과 최소값

#include <iostream>
#include <vector>
using namespace std;

void solution(int start, int end);

int main()
{
		int start, end;
		cin >> start >> end;
		solution(start, end);
		return 0;
}

void solution(int start, int end) {
		vector<int> v(end + 1);
		int total = 0, min;

		for (int i = 2; i <= end; i++)
				v[i] = i;

		for (int i = 2; i <= end; i++) {
				if (v[i] == 0) continue;
				for (int k = i + i; k<= end; k += i)
						v[k] = 0;
		}

		for (int i = start; i <= end; i++)
				if (v[i] != 0) total += v[i];

		for (int i = start; i <= end; i++) {
				if (v[i] != 0) {
						min = v[i];
						break;
				}
		}

		if (total == 0) cout << "-1\n";
		else
				cout << total << "\n" << min;
}