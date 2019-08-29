/// 2017 kakao blind coding test 3 : auto completion

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> words);

int main()
{

	return 0;
}

int solution(vector<string> words) {
	int answer = 0;
	int diffWord = 1;

	sort(words.begin(), words.end());
	
	for (int i = 0; i < words.size()-1; i++) {
		if (words[i][0] != words[i + 1][0])
			diffWord++;
	}
	if (words.size() == diffWord)
		return diffWord;



	return answer;
}