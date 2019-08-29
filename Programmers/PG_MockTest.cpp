#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a = { 1,2,3,4,5 };
vector<int> b = { 2,1,2,3,2,4,2,5};
vector<int> c = { 3,3,1,1,2,2,4,4,5,5 };
vector<int> solution(vector<int> answers);

int main()
{
	vector<int> tmp = solution({ 1,3,2,4,2});
	for (auto t : tmp)
		cout << t << " ";
	cout << endl;
	return 0;
}

vector<int> solution(vector<int> answers) {
	vector<pair<int,int>> answer(3);
	
	for (int i = 0; i < answer.size(); i++) {
		answer[i].second = i + 1;
		answer[i].first = 0;
	}

	for (int i = 0; i < answers.size(); i++) {
		if (a[i%a.size()] == answers[i])
			answer[0].first++;
		if (b[i%b.size()] == answers[i])
			answer[1].first++;
		if (c[i%c.size()] == answers[i])
			answer[2].first++;
	}

	sort(answer.begin(), answer.end());

	int maxVal = 0;
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i].first > maxVal)
			maxVal = answer[i].first;
	}

	vector<int> res;
	
	for (int i = 0; i < answer.size(); i++)
		if (answer[i].first != 0 && answer[i].first == maxVal)
			res.push_back(answer[i].second);

	return res;
}