#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> foodTimes, long long k) {
	int index=0;
	int total = 0;
	long long time = 0;
	int len = foodTimes.size();

	for (int i = 0; i < len; i++)
		total += foodTimes[i];

	while (1) {
		if (foodTimes[index] != 0) {
			foodTimes[index]--;
			total--;
			time++;
			//for (auto t : foodTimes)
			//	cout << t << " ";
			//cout << endl;
			//cout << index << endl;
		}
		index++;
		index %= len; // ´ÙÀ½ ÀÎµ¦½º
		if (total == 0 || time == k)
			break;
	}
	
	return total != 0 ? index+1 : -1;
}

int main()
{
	cout << solution({ 3,1,2 }, 5) << endl;
	cout << solution({ 1,10,10,10,10,10,10 }, 14);
	return 0;
}