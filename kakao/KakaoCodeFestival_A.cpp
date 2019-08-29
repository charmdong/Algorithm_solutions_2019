#include <iostream>
#include <vector>
using namespace std;

void solution(int a, int b);

int main()
{
	int n, a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		solution(a, b);
	}
	return 0;
}

void solution(int a, int b) {
	if ((a == 0 && b == 0)) {
		cout << "0\n";
		return;
	}
	
	vector<int> v1 = { 0,500,300,300,200,200,200,50,50,50,50,30,30,30,30,30,10,10,10,10,10,10 };
	vector<int> v2 = {0, 512, 256,256,128,128 ,128 ,128 ,64,64 ,64 ,64 ,64 ,64 ,64 ,64 ,32,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 };

	if (a <= 21 && b <= 31)
		cout << (v1[a] + v2[b]) * 10000 << '\n';
	else if (a > 21 && b <= 31)
		cout << v2[b] * 10000 << '\n';
	else if (a <= 21 && b > 31)
		cout << v1[a] * 10000 << '\n';
	else
		cout << "0\n";
}