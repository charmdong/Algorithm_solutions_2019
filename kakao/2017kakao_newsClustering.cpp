/// 2017 kakao blind coding test : News Clustering

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MUL 65536
using namespace std;

vector<string> a, b;

void upper(string& str);
void parsing(string str1, string str2);
int solution(string str1, string str2);

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	
	cout << solution(str1, str2);
	return 0;
}

void upper(string& str) {
	for (auto& t : str)
		t = toupper(t);
}

void parsing(string str1, string str2) {
	int len1 = str1.length();
	int len2 = str2.length();

	upper(str1);
	upper(str2);

	for (int i = 0; i < len1 - 1; i++) {
		string tmp = str1.substr(i, 2);
		if (tmp[0] < 65 || tmp[0] > 90 || tmp[1] < 65 || tmp[1] > 90)
			continue;
		a.push_back(tmp);
	}

	for (int i = 0; i < len2 - 1; i++) {
		string tmp = str2.substr(i, 2);
		if (tmp[0] < 65 || tmp[0] > 90 || tmp[1] < 65 || tmp[1] > 90)
			continue;
		b.push_back(tmp);
	}
}

int solution(string str1, string str2) {
	double inter, uni;
	vector<string> kyo, hap;
	
	parsing(str1, str2);
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(hap));
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(kyo));

	
	//for (auto t : hap)
	//	cout << t << " ";
	//cout << endl;
	//for (auto t : kyo)
	//	cout << t << " ";
	//cout << endl;

	inter = kyo.size();
	uni = hap.size();

	if (inter == 0 && uni == 0)
		return MUL;
	return (inter / uni) * MUL;
}