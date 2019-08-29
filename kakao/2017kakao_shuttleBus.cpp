/// 2017 kakao blind coding test : shuttle bus

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> timecase;
vector<string> shuttleTime;
string solution(int n, int t, int m, vector<string> timetable);
void getShuttleTime(int n, int t);
void getTimeCase(vector<string> timetable);
void normalizeTimeCase(int m);

int main()
{
	//cout << solution(2, 10, 2, { "09:10", "09:09", "09:07","09:06","08:00" }) << endl;
	cout << solution(10, 59, 45, {}) << endl;

	return 0;
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	
	sort(timetable.begin(), timetable.end());
	getShuttleTime(n, t);
	
	timecase.resize(n, 0);
	getTimeCase(timetable);
	normalizeTimeCase(m);

	if (timecase[n - 1] >= m) {
		int index = 0;
		string hour = "", min = "";
		for (int i = 0; i < timecase.size() - 1; i++)
			index += timecase[i];
		index += m;
		hour = timetable[index - 1].substr(0, 2);
		min = timetable[index - 1].substr(3, 2);

		if (min[1] == '0') {
			if (min[0] == '0') { // 00
				min = "59";
				if (hour == "10" || hour == "20") {
					hour[0]--;
					hour[1] += 9;
				}
				else
					hour[1]--;
			}
			else { // 10,20,30,40,50
				min[0]--;
				min[1] += 9;
			}
		}
		else 
			min[1]--;
		answer += hour + ":" + min;
	}
	else
		answer = shuttleTime[n - 1];
	return answer;
}

void getShuttleTime(int n, int t) {
	int hour = 9, min = -t;
	string h = "", m = "";

	for (int i = 0; i < n; i++) {
		min += t;
		if (min >= 60) {
			hour++;
			min %= 60;
		}
		h = (hour < 10) ? ("0" + to_string(hour)) : to_string(hour);
		m = (min < 10) ? ("0" + to_string(min)) : to_string(min);
		shuttleTime.push_back(h + ":" + m);
	}
}

void getTimeCase(vector<string> timetable) {
	int timeLen = timetable.size();
	int shuttleLen = shuttleTime.size();
	int cnt = 0, k = 0;

	for (int i = 0; i < shuttleLen; i++) {
		if (i == 0) {
			for (k = 0; k < timeLen; k++) {
				if (timetable[k] > shuttleTime[i]) break;
				cnt++;
			}
		}
		else {
			for (int j = k; j < timeLen; j++) {
				if (timetable[j] > shuttleTime[i - 1] && timetable[j] <= shuttleTime[i])
					cnt++;
			}
		}
		timecase[i] = cnt;
		cnt = 0;
	}
}

void normalizeTimeCase(int m) {
	int len = timecase.size();

	for (int i = 0; i < len - 1; i++) {
		if (timecase[i] > m) {
			timecase[i + 1] += (timecase[i] - m);
			timecase[i] -= (timecase[i] - m);
		}
	}
}