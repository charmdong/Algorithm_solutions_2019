#include <iostream>
#include <math.h>
using namespace std;

int n;

int main()
{
	cin >> n;
	int quo = 0, len = 0;
	
	int tmp = n;
	while (tmp / 10 != 0) {
		tmp /= 10;
		quo++;
	}
	
	for (int i = 1; i <= quo; i++)
		len += (i * 9 * pow(10, i-1));
	len += (n - (pow(10, quo)) + 1) * (quo + 1);

	cout << len << endl;
	return 0;
}