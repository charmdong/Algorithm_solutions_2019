#include <iostream>
#include <vector>
using namespace std;

int total, cnt, index;
int dfs(vector<int> numbers, int target);

int main()
{
	int target = 3;
	vector<int> numbers = { 1,1,1,1,1 };
	cout << dfs(numbers, target) << endl;
	return 0;
}

int dfs(vector<int> numbers, int target) {
	if (index == numbers.size()) {
		if (total == target)
			return 1;
		return 0;
	}

	total += numbers[index++];
	int res1 = dfs(numbers, target);
	total -= numbers[--index];
	total += -numbers[index++];
	int res2 = dfs(numbers, target);
	total -= -numbers[--index];

	return res1 + res2;
}