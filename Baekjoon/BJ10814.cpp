/**
 * @author : donggun.chung
 * @date : 2020.02.09
 * @site : BOJ
 * @prob_Info : 10814 나이순 정렬
 * @time : 112ms
 * @memory : 9816KB
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, string>> members;

bool compare(pair<int, string> &p1, pair<int, string> &p2) {
	return p1.first < p2.first;
}

int main()
{
	cin >> N;

	members.assign(N, {0, ""});

	for(int index = 0; index < N; index++) {
		cin >> members[index].first >> members[index].second;
	}

	stable_sort(members.begin(), members.end(), compare);

	for(auto m : members) {
		cout << m.first << " " << m.second << "\n";
	}

	return 0;
}