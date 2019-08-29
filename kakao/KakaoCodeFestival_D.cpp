#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(vector<pair<int, int>> p, int start, int end, int hp);

int main()
{
	int n, q;
	vector<pair<int, int>> p;
	p.push_back(pair<int, int>(0,0));
	cin >> n >> q;
	while (n--) {
		int x, y;
		cin >> x >> y;
		p.push_back(pair<int, int>(x, y));
	}
	while (q--) {
		int start, end, hp;
		cin >> start >> end >> hp;
		solution(p, start, end, hp);
	}
	return 0;
}

void solution(vector<pair<int, int>> p, int src, int des, int hp) {
	// 체크포인트들끼리 연결이 되는지 확인해야한다.
	// check[src][des] == true 인지 판별할 수 있어야한다. 다른 체크포인트들을 거쳐서 연결되는 경우도 생각해야함
	// check[src][des] == false 인 경우에는 x,y 축 중 긴 거리를 부스터를 사용하고,
	// x,y 축 중 짧은 거리가 hp보다 작거나 같으면 이동 가능하다.
	// 나머지 경우는 이동할 수 없음.
	if (p[src].first == p[des].first || p[src].second == p[des].second) {
		cout << "YES\n";
		return;
	}

	pair<int, int> check1(p[des].first, p[src].second);
	pair<int, int> check2(p[src].first, p[des].second);

	if (find(p.begin(), p.end(), check1) != p.end() || find(p.begin(), p.end(), check2) != p.end()) {
		cout << "YES\n";
		return;
	}

	if (hp != 0) {
		int min;
		int x = abs(p[src].first - p[des].first);
		int y = abs(p[src].second - p[des].second);
		min = x > y ? y : x;
		if (hp >= min) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

/*
input :
5 3
1 2
3 2
4 4
6 2
3 9
1 5 0
3 4 0
3 4 2

output :
YES
NO
YES
*/