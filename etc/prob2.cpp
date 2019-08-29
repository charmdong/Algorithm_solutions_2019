/*
�Լ��� �ԷµǴ� �ð��� 12�ð� ǥ�������, AM/PM�� �Բ� ǥ��˴ϴ�.

24�ð� ǥ������� Ǯ���ϸ� ������ �����ϴ�.

00:00:00 ~ 11:59:59 --> AM 00:00:00 ~ AM 11:59:59
12:00:00 ~ 23:59:59 --> PM 00:00:00 ~ PM 11:59:59

�Էµ� ù��° �ð����� �ι�° �ð��� �Ǵµ� �ɸ��� �ð��� ���ϴ� �Լ��� �����Ͻÿ�.

(AM 00:00:01, AM 00:00:02) �� �ԷµǸ�, ù��° �ð����� �ι�° �ð��� �Ǳ���� �ɸ��� �ð��� 1�� �̹Ƿ� 00:00:01 ���ϵ˴ϴ�.
(PM 01:00:00, AM 01:00:00) �� �ԷµǸ�, ù��° �ð����� �ι�° �ð��� �Ǳ���� �ɸ��� �ð��� 12�ð� �̹Ƿ� 12:00:00�� ���ϵ˴ϴ�.

*����1: �Է½ð����� valid�մϴ�.
*����2: AM 00:00:00�� �Էµ��� �ʽ��ϴ�.
*����3: Date, time, difftime �� �ý��� ���� class/function ������� �ʾƾ� �մϴ�
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
	// �� �� �ʰ� 10���� ���� ��� ���
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