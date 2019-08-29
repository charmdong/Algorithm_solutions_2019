/// 택시 기하학

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

void solution(int r);

int main()
{
	int r;
	cin >> r;
	solution(r);
	return 0;
}

void solution(int r) {
	printf("%.6f\n", M_PI*r*r);
	printf("%.6f\n", 2.0*r*r);
}