#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<string> tmp = record;
	vector<string> uid, nick;

	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++) {
		string id, nic;
		int index = tmp[i].find(' ', 0);
		if (tmp[i].substr(0, index) == "Leave")
			break;
		tmp[i] = tmp[i].substr(index + 1);
		index = tmp[i].find(' ', 0);
		id = tmp[i].substr(0, index);
		nic = tmp[i].substr(index + 1);
		int check = 0;
		for (int k = 0; k < uid.size(); k++) {
			if (uid[k] == id) {
				nick[k] == nic;
				check = 1;
			}
		}
		if (check == 0) {
			nick.push_back(nic);
			uid.push_back(id);
		}
	}
	tmp = record;
	for (int i = 0; i < tmp.size(); i++) {
		string id, op;
		int index = tmp[i].find(' ', 0);
		op = tmp[i].substr(0, index);
		if (op != "Change") {
			tmp[i] = tmp[i].substr(index + 1);
			index = tmp[i].find(' ', 0);
			id = tmp[i].substr(0, index);
			for (int k = 0; k < uid.size(); k++) {
				if (uid[k] == id)
					op == "Enter" ? answer.push_back(nick[k] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.") : answer.push_back(nick[k] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
			}
		}
	}
	return answer;
}

int main() {
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };
	vector<string> res = solution(record);
	for (auto t : res)
		cout << t << " ";
	cout << endl;
	return 0;
}
