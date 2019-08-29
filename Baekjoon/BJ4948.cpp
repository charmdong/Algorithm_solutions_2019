/// 베르트랑 공준
#include <iostream>
#include <vector>
using namespace std;

void solution(int start, int end);

int main()
{
		int num;
		while (true) {
				cin >> num;
				if (num == 0)
						break;
				solution(num+1, num * 2);
		}
		return 0;
}

void solution(int start, int end) {
		int total = 0;
		vector<int> v(end + 1);

		for (int i = 2; i <= end; i++)
				v[i] = i;

		for (int i = 2; i <= end; i++) {
				if (v[i] == 0)
						continue;
				for (int j = i + i; j <= end; j += i)
						v[j] = 0;
		}

		for (int i = start; i <= end; i++) {
				if (v[i] != 0) {
						//cout << v[i] << endl;
						total++;
				}
		}
		cout << total << "\n";
}