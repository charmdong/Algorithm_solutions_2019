#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

void solution(vector<int> xList, vector<int> yList, int src, int des, int hp);

int main()
{
	vector<int> xList, yList;
	xList.push_back(0);
	yList.push_back(0);
	int n, q;
	cin >> n >> q;
	
	while (n--) {
		int x, y;
		cin >> x >> y;
		xList.push_back(x);
		yList.push_back(y);
	}

	while (q--) {
		int src, des, hp;
		cin >> src >> des >> hp;
		solution(xList, yList, src, des, hp);
	}
	return 0;
}

void solution(vector<int> xList, vector<int> yList, int src, int des, int hp) {
	if (xList[src] == xList[des] || yList[src] == yList[des]) {
		cout << "YES\n";
		return;
	}
	
	int len = xList.size();
	for (int i = 1; i < len; i++) {
		if ((xList[i] == xList[src] && yList[i] == yList[des]) || (xList[i] == xList[des] && yList[i] == yList[src])) {
			cout << "YES\n";
			return;
		}
	}

	if (hp >= abs(xList[src] - xList[des]) || hp >= abs(yList[src] - yList[des])) {
		cout << "YES\n";
		return;
	}

	cout << "NO\n";
}