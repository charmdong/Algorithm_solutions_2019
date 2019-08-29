/*
함수에 입력되는 시간은 12시간 표기법으로, AM/PM과 함께 표기됩니다.

24시간 표기법으로 풀이하면 다음과 같습니다.

00:00:00 ~ 11:59:59 --> AM 00:00:00 ~ AM 11:59:59
12:00:00 ~ 23:59:59 --> PM 00:00:00 ~ PM 11:59:59

입력된 첫번째 시간에서 두번째 시간이 되는데 걸리는 시간을 구하는 함수를 구현하시오.

(AM 00:00:01, AM 00:00:02) 가 입력되면, 첫번째 시간에서 두번째 시간이 되기까지 걸리는 시간은 1초 이므로 00:00:01 리턴됩니다.
(PM 01:00:00, AM 01:00:00) 가 입력되면, 첫번째 시간에서 두번째 시간이 되기까지 걸리는 시간은 12시간 이므로 12:00:00이 리턴됩니다.

*조건1: 입력시간값은 valid합니다.
*조건2: AM 00:00:00은 입력되지 않습니다.
*조건3: Date, time, difftime 등 시스템 제공 class/function 사용하지 않아야 합니다
*/
#include <iostream>

#include <string>
#include <vector>
using namespace std;

string solution(string statr, string end);
void parsing(string str, string &c, int &t, int &m, int &s);

int main()
{
	string start, end;
	getline(cin, start);
	getline(cin, end);
	cout << solution(start, end);
	return 0;
}

string solution(string start, string end) {
	string answer = "";
	string startCheck, endCheck;
	int startHour, endHour;
	int startMin, endMin;
	int startSec, endSec;
	int startTotal = 0, endTotal = 0;
	int diffTotal=0;
	int diffHour, diffMin, diffSec;

	parsing(start, startCheck, startHour, startMin, startSec);
	parsing(end, endCheck, endHour, endMin, endSec);

	startTotal += (startHour * 3600) + (startMin * 60) + startSec;
	endTotal += (endHour * 3600) + (endMin * 60) + endSec;

	// start, end = AM or PM
	if (startCheck == endCheck) {
		if (startTotal < endTotal) 
			diffTotal = endTotal - startTotal;
		else if(startTotal > endTotal)
			diffTotal = (24*3600) - (startTotal - endTotal);

	}

	else {
		// start = AM, end = PM
		if (startCheck == "AM") {
			endTotal += (12 * 3600);
			diffTotal = endTotal - startTotal;
		}
		// start = PM, end = AM
		else {
			startTotal += (12 * 3600);
			diffTotal = (24*3600) - (startTotal - endTotal);
		}
	}

	diffHour = diffTotal / 3600;
	diffMin = (diffTotal % 3600) / 60;
	diffSec = diffTotal % 60;
	// 시 분 초가 10보다 작은 경우 고려
	if (diffHour < 10)
		answer += "0";
	answer += to_string(diffHour)+":";
	
	if (diffMin < 10)
		answer += "0";
	answer += to_string(diffMin)+":";

	if (diffSec < 10)
		answer += "0";
	answer += to_string(diffSec);

	return answer;
}

void parsing(string str, string &c, int &t, int &m, int &s) {
	c = str.substr(0, 2);
	t = stoi(str.substr(3, 2));
	m = stoi(str.substr(6, 2));
	s = stoi(str.substr(9, 2));
}