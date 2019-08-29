/// 프린터 큐

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(vector<int>& q1, vector<int>& q2, int m);

int main()
{
		int testCase, n, m;
		cin >> testCase;

		while (testCase--) {
				cin >> n >> m;
				vector<int> q1, q2;

				for (int i = 0; i < n; i++) {
						int important;
						q2.push_back(i);
						cin >> important;
						q1.push_back(important);
				}
				solution(q1, q2, m);
		}
		return 0;
}

void solution(vector<int>& q1, vector<int>& q2, int m) {
		int cnt = 0;
		
		while (!q1.empty()) {
				if (q1.front() == *max_element(q1.begin(), q1.end())) {
						cnt++;
						if (q2.front() == m) {
								cout << cnt << endl;
								return;
						}
						q1.erase(q1.begin());
						q2.erase(q2.begin());
				}
				else {
						q1.push_back(q1.front());
						q1.erase(q1.begin());
						q2.push_back(q2.front());
						q2.erase(q2.begin());
				}
		}
}