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
	// üũ����Ʈ�鳢�� ������ �Ǵ��� Ȯ���ؾ��Ѵ�.
	// check[src][des] == true ���� �Ǻ��� �� �־���Ѵ�. �ٸ� üũ����Ʈ���� ���ļ� ����Ǵ� ��쵵 �����ؾ���
	// check[src][des] == false �� ��쿡�� x,y �� �� �� �Ÿ��� �ν��͸� ����ϰ�,
	// x,y �� �� ª�� �Ÿ��� hp���� �۰ų� ������ �̵� �����ϴ�.
	// ������ ���� �̵��� �� ����.
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