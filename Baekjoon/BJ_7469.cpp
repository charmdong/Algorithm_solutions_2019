#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void res(vector<int>, int, int, int);

int main()
{
		int totalCnt, callCnt, sIndex, eIndex, search;

		scanf("%d %d", &totalCnt, &callCnt);
		vector<int> v(totalCnt, 0);

		for (int i = 0; i<totalCnt; i++) {
				scanf("%d", &v[i]);
		}

		while (callCnt--) {
				scanf("%d %d %d", &sIndex, &eIndex, &search);
				//res(v, sIndex, eIndex, search);
				vector<int> tmp;
				tmp.assign(v.begin() + sIndex - 1, v.begin() + eIndex);
				sort(tmp.begin(), tmp.end());
				cout << tmp[search - 1] << endl;
		}

		return 0;
}

void res(vector<int> v, int sIndex, int eIndex, int search) {
		vector<int> tmp;
		tmp.assign(v.begin() + sIndex - 1, v.begin() + eIndex);
		sort(tmp.begin(), tmp.end());
		cout << tmp[search - 1] << endl;
}