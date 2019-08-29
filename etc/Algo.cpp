//#include <math.h>
#include <iostream>
#include <string>
using namespace std;

int res(int num);
bool isStair(string check);
int test(int);
// BJ10844
int main()
{
		cin.tie(NULL);
		cin.sync_with_stdio(false);
		
		int num;
		cin >> num;
		cout << res(num);
		return 0;
}

int res(int num) {
		string check;
		int cnt = 0;
		int start = pow(10, num - 1);
		int end = pow(10, num);

		for (int i = start; i < end; i++) {
				check = to_string(i);
				if (isStair(check)) {
						cnt++;
						cnt %= 1000000000;
				}
		}

		return cnt;
}

bool isStair(string check) {
		for (int i = 0; i < (int)check.length()-1; i++) {
				if (abs((check[i + 1] - '0') - (check[i] - '0')) != 1)
						return false;
		}
		return true;
}

int test(int num) {

}