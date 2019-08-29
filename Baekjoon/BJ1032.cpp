#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ary;
string solution(vector<string> ary);

int main()
{
	int n;
	cin >> n;
	ary.assign(n,"");
	for (int i = 0; i < n; i++)
		cin >> ary[i];
	cout << solution(ary) << endl;
	return 0;
}

string solution(vector<string> ary) {
	string ans;
	int len = ary[0].length();

	for (int i = 0; i < len; i++) {
		bool same = true;
		char check = ary[0][i];
		for (int j = 1; j < ary.size(); j++) {
			if (check == ary[j][i]) continue;
			ans += "?";
			same = false;
			break;
		}
		if (same)
			ans += ary[0][i];
	}
	
	return ans;
}