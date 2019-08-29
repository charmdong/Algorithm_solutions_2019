#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
		int len, index;
		scanf("%d%d", &len, &index);
		vector<int> ary(len, 5);

		for (int i = 0; i<len; i++) {
				scanf("%d", &ary[i]);
		}

		sort(ary.begin(), ary.end());
		printf("%d", ary[index - 1]);
	
		return 0;
}