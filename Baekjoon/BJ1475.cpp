#include <iostream>
#include <vector>
using namespace std;

void res(int num);
int getMax(vector<int>);

int main()
{
		int num;
		cin >> num;
		res(num);
		return 0;
}

void res(int num) {
		if (num == 0) {
				cout << "1";
				return;
		}
		
		vector<int> tmpList(10, 0);
		
		for (int i = 0; num != 0; i++) {
				int tmp = num % 10; // 각 자리 수
				if (tmp == 6)
						tmpList.at(tmp + 3)++;
				else
						tmpList.at(tmp)++;
				num /= 10;
		} // Result of Parsing parameter
		tmpList.at(9) = tmpList.at(9) / 2.0 + 0.5;
		
		cout << getMax(tmpList);
}

int getMax(vector<int> list) {
		int max = list.at(0);
		
		for (int i = 1; i < list.size(); i++) {
				if (list.at(i) > max) {
						max = list.at(i);
				}
		}

		return max;
}