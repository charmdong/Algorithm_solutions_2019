/// 소수 구하기 : 에라토스테네스의 체
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
		vector<int> v(end+1);
		
		for (int i = 2; i <= end; i++)
				v[i] = i;

		for (int i = 2; i <= end; i++) {
				if (v[i] == 0)
						continue;
				for (int j = i+i; j <= end; j+=i)
						v[j] = 0;
		}

		for (int i = start; i <= end; i++) {
				if (v[i] != 0)
						cout << v[i] << "\n";
		}
}