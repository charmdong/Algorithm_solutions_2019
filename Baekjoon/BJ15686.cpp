#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> chicken, home;
vector<int> position ,res;
void solution(int index = 0,int cnt = 0);

int main()
{
	cin >> n >> m;
	
	int tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			if (tmp == 1)
				home.push_back({ i,j });
			if (tmp == 2)
				chicken.push_back({ i,j });
		}
	}
	solution();
	cout << *min_element(res.begin(), res.end()) << endl;

	return 0;
}

void solution(int index, int cnt) {
	if (cnt == m) {
		int total = 0;
		for (int i = 0; i < home.size(); i++) { // ¸ðµç Áýµé
			int ans = 100;
			for (int j = 0; j < m; j++) { // ¼±ÅÃµÈ Ä¡Å²Áýµé
				ans = min(ans, abs(home[i].first - chicken[position[j]].first)
				 + abs(home[i].second - chicken[position[j]].second));
			}
			total += ans;
		}
		res.push_back(total);
		return;
	}

	for (int i = index; i < chicken.size(); i++) {
		position.push_back(i);
		solution(i+1, cnt + 1);
		position.pop_back();
	}
}