/// N-Queen 서로를 한번에 공격할 수 없도록 퀸을 배치.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cnt = 0;

void enumerate(int n);
void enumerate(vector<int>& v, int n);
bool isAvailable(vector<int>& v, int n);

int main()
{
		int n;
		cin >> n;
		enumerate(n);
		cout << cnt << endl;
		return 0;
}

void enumerate(int n) {
		vector<int> v(n, 0);
		enumerate(v, 0);
}

void enumerate(vector<int>& v, int n) {
		int end = v.size();
		if (n == end)
				cnt++;
		else {
				for (int i = 0; i < end; i++) {
						v[n] = i;
						if (isAvailable(v, n)) enumerate(v, n + 1);
				}
		}
}

bool isAvailable(vector<int>& v, int n) {
		for (int i = 0; i < n; i++)
				if (v[i] == v[n] || (v[i] - v[n] == n - i) || (v[n] - v[i] == n - i)) return false;
		return true;
}