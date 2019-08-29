#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> relation) {
	int res = 0;

	vector<int> index; // 후보키가 될 수 없는 속성의 인덱스
	vector<vector<string>> notCandi;

	int cardi = relation[0].size(); // 속성 수
	for (int i = 0; i < cardi; i++) {
		int check = 1;
		for (int k = 0; k < relation.size() - 1; k++) {
			for (int j = k + 1; j < relation.size(); j++) {
				if (relation[k][i] == relation[j][i]) {
					index.push_back(i);
					check = 0;
					break;
				}
			}
			if (check == 0)
				break;
		}
		if (check)
			res++;
	}
	
	for (int i = 0; i < relation.size(); i++) { // 행
		vector<string> str;
		for (int k = 0; k < index.size(); k++)
			str.push_back(relation[i][index[k]]);
		notCandi.push_back(str);
	}

	for (int i = 0; i < index.size(); i++) {
		for (int k = 0; k < notCandi.size(); k++) {
			string str; 
			str+=notCandi[k][i];
		}
	}
	
	return res;
}

int main()
{
	solution({ {"100", "ryan", "music", "2"},{"200", "apeach", "math", "2"},{"300","tube", "computer", "3"},{"400", "con", "computer", "4"},{"500", "muzi", "music", "3"},{"600", "apeach", "music", "2"} });
	return 0;
}