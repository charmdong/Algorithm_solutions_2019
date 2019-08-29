#include <iostream>
#include <string>
using namespace std;

void res();

int main()
{
		res();
		return 0;
}

void res() {
		int n1, n2, n3, total;
		int ary[10] = { 0 };
		cin >> n1 >> n2 >> n3;
		total = n1 * n2 * n3;

		string tmp = to_string(total);
		for (int i = 0; i < tmp.length(); i++) {
				ary[tmp[i] - '0']++;
		}

		for(int i=0; i<sizeof(ary)/sizeof(ary[0]); i++){
				cout << ary[i] << endl;
		}
}