/// ¸·´ë±â

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> stick;
int solution(int n);

int main()
{
	cin >> n;
	stick.push_back(64);
	cout << solution(n) << endl;
	return 0;
}

int solution(int n) {
	while (true) {
		int total = 0;
		for (int t : stick)
			total += t;
		
		if (total <= n) break;

		sort(stick.begin(), stick.end());
		
		stick[0] /= 2;
		if ((total - stick[0]) < n) 
			stick.push_back(stick[0]);
	}
	return stick.size();
}