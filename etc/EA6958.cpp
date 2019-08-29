#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int solution(vector<int> s, int high);

int main()
{
	int test, num, cnt=0;
	
	cin >> test;
	for(int k=0; k<test; k++) {
		cin >> n >> m;
		vector<int> score;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> num;
				if (num == 1) cnt++;
			}
			score.push_back(cnt);
			cnt = 0;
		}
		int high = *max_element(score.begin(), score.end());
		cout << "#" << k+1 << " " << solution(score, high) << " " << high << endl;
	}
	
	return 0;
}

int solution(vector<int> score, int high) {
	return count(score.begin(), score.end(), high);
}