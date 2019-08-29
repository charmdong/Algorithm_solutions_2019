#include <iostream>
#include <vector>
using namespace std;

void res(vector<int> v, int num);

int main()
{
	vector<int> v;
	int len, num,tmp;

	cin >> len;
	cin >> num;
	while (len--) {
		cin >> tmp;
		v.push_back(tmp);
	}

	res(v, num);
	return 0;
}

void res(vector<int> v, int num)
{
	for (int i = 0; i < v.size(); i++)
		if (v[i] < num)
			cout << v[i] << " ";
}