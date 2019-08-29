/// 조세퍼스

#include <iostream>
#include <queue>
using namespace std;

void solution(int n, int m);

int main()
{
		int n, m;
		cin >> n >> m;
		solution(n, m);
		return 0;
}

void solution(int n, int m) {
		int cnt = 1;
		queue<int> q;
		for (int i = 0; i < n; i++)
				q.push(i + 1);

		cout << "<";
		while (q.size() != 1) {
				if (cnt != m) {
						q.push(q.front());
						q.pop();
						cnt++;
				}
				else {
						cout << q.front() << ", ";
						q.pop();
						cnt = 1;
				}
		}
		cout << q.front() << ">\n";
}