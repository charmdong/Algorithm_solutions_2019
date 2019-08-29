#include <iostream>

#include <string>
#include <vector>
using namespace std;

int getIndex(vector<pair<string, int>> v, string str) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == str)
			return i;
	}
	return -1;
}

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	vector<pair<string, int>> v;
	for (int i = 0; i < clothes.size(); i++) {
		int idx = getIndex(v, clothes[i][1]);
		if (idx == -1)
			v.push_back({ clothes[i][1], 1 });
		else
			v[idx].second++;
	}

	for (auto t : v)
		answer *= (t.second + 1);

	return answer - 1;
}

int main()
{
	cout << solution({ {"yellow_hat", "headgear"}, { "blue_sunglasses", "eyewear" }, { "green_turban", "headgear" } });
	return 0;
}