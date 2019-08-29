#include <iostream>
#include <set>
#define MAX 10000
using namespace std;

int selfNum(int num);

int main()
{
	set<int> s;
	for (int i = 1; i <= MAX; i++)
		s.insert(selfNum(i));
	
	for (int i = 1; i <= MAX; i++)
		if (s.find(i) == s.end())
			cout << i << endl;
	
	return 0;
}

int selfNum(int num)
{
	if (num / 10 == 0)
		return num * 2;

	int sum = num;
	while (1) {
		sum += (num % 10);
		num /= 10;
		if (num == 0)
			return sum <= MAX ? sum : 0;
	}
}