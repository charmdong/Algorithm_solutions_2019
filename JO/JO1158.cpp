/// 1158 : »ðÀÔ Á¤·Ä

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& v);
void printAry(vector<int> v);

int main()
{
		vector<int> v;
		int len;
		cin >> len;
		for (int i = 0; i < len; i++) {
				int source;
				cin >> source;
				v.push_back(source);
		}
		insertionSort(v);

		return 0;
}

void insertionSort(vector<int>& v) {
		size_t size = v.size();
		
		for (int i = 1; i < size; i++) {
				for (int k = 0; k < i; k++) {
						if (v[k] > v[i]) {
								int tmp = v[i];
								for (int cur = i; cur > k; cur--)
										v[cur] = v[cur - 1];
								v[k] = tmp;
								break;
						}
				}
				printAry(v);
		}
}

void printAry(vector<int> v) {
		for (int t : v)
				cout << t << " ";
		cout << "\n";
}