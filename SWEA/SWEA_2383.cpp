// 점심 식사시간
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct person {
	int y, x;
	int dist1, dist2;
	person(int y, int x) :y(y), x(x) {}
};

struct stair {
	int y, x;
	int h;
	stair(int y, int x, int h) :y(y), x(x), h(h) {}
};

int N;
int map[10][10];


int main()
{
	int test;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		cin >> N;

		vector<person> p;
		vector<stair> s;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> map[i][j];
				if (map[i][j] == 1)
					p.push_back(person(i, j));
				else if (map[i][j] > 1)
					s.push_back(stair(i, j, map[i][j]));
			}
		}

		for (int i = 0; i < p.size(); i++) {
			p[i].dist1 = abs(p[i].y - s[0].y) + abs(p[i].x - s[0].x);
			p[i].dist2 = abs(p[i].y - s[1].y) + abs(p[i].x - s[1].x);
		}


	}
	return 0;
}