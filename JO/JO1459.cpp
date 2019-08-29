/// 1459 : 숫자고르기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxCnt = 0, tmpCnt = 0, num;
vector<int> maxArray;
vector<vector<int>> v(2, vector<int>());

void selectNum(int index, vector<int>& top, vector<int>& bottom);

int main()
{
		cin >> num;
		vector<int> top, bottom;

		for (int i = 0; i < num; i++) {
				v[0].push_back(i + 1);
				int tmpNum;
				cin >> tmpNum;
				v[1].push_back(tmpNum);
		}
		selectNum(0, top, bottom);

		cout << maxCnt << "\n";
		for (auto t : maxArray)
				cout << t << "\n";

		return 0;
}

void selectNum(int index, vector<int>& top, vector<int>& bottom) {
		for (int i = index; i < num; i++) {
				top.push_back(i + 1);
				bottom.push_back(v[1][i]);
				tmpCnt++;

				if (tmpCnt == 1) {
						if ((top == bottom) && !maxCnt) {
								maxCnt = tmpCnt;
								maxArray = top;
						}
						selectNum(i + 1, top, bottom);
				}
				else {
						vector<int> tmp = bottom;
						sort(tmp.begin(), tmp.end());
						if (top == tmp) {
								if (tmpCnt > maxCnt) {
										maxCnt = tmpCnt;
										maxArray = top;
								}
								selectNum(i + 1, top, bottom);
						}
				}
				tmpCnt--;
				top.pop_back();
				bottom.pop_back();
		}
}