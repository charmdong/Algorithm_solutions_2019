/// 2017 kakao dart

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> allScores;
vector<char> allOptions;

void parsing(string dartResult);
int solution(string dartResult);

int main()
{
	string dartResult;
	cin >> dartResult;
	parsing(dartResult);
	cout << solution(dartResult);
	return 0;
}

void parsing(string dartResult) {
	int score, len = dartResult.length();
	char bonus = '\0', option = '\0';

	for (int i = 0; i < len; i++) {
		if (dartResult[i] >= '0' && dartResult[i] <= '9') {
			if (dartResult[i] == '1') {
				score = (dartResult[i + 1] == '0') ? 10 : 1;
				i++;
			}
			else
				score = dartResult[i] - '0';
		}
		else if (dartResult[i] == '*' || dartResult[i] == '#')
			option = dartResult[i];
		else
			bonus = dartResult[i];

		if (i == len - 1 || (dartResult[i + 1] >= '0' && dartResult[i + 1] <= '9')) {
			switch (bonus) {
			case 'S': score *= 1; break;
			case 'D': score *= score; break;
			case 'T': score *= (score*score);
			}
			if (option == '#')
				score *= -1;
			allScores.push_back(score);
			allOptions.push_back(option);
			option = '\0';
		}
	}
}

int solution(string dartResult)
{
	parsing(dartResult);
	int res = 0, len = allScores.size();

	for (int i = 1; i < len; i++) {
		if (allOptions[i] == '*') 
			res += (allOptions[i - 1] == '*') ? (allScores[i - 1] * 4) : (allScores[i - 1] * 2);
		else
			res += (allOptions[i - 1] == '*') ? (allScores[i - 1] * 2) : (allScores[i - 1]);
	}
	res += (allOptions[len - 1] == '*') ? allScores[len - 1] * 2 : allScores[len - 1];

	return res;
}