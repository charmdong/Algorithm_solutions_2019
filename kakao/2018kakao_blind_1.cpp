#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<string> nick;
	vector<string> uid;

	for (int i = 0; i < record.size(); i++) {
		string oper, nic, id;
		string tmp = record[i];
		int index = tmp.find(' ', 0);

		oper = tmp.substr(0, index);
		if (oper != "Leave") {
			tmp = tmp.substr(index + 1);
			index = tmp.find(' ', 0);
			id = tmp.substr(0, index);
			nic = tmp.substr(index + 1);
			if (oper == "Enter") {
				int check = 0;
				for (int k = 0; k < uid.size(); k++) {
					if (uid[k] == id) {
						nick[k] = nic;
						check = 1;
					}
				}
				if (check == 0) {
					nick.push_back(nic);
					uid.push_back(id);
				}
			}
			else {
				for (int k = 0; k < uid.size(); k++) {
					if (uid[k] == id)
						nick[k] = nic;
				}
			}
		}
	}
	for (int i = 0; i < record.size(); i++) {
		string oper, nic, id;
		string tmp = record[i];
		int index = tmp.find(' ', 0);

		oper = tmp.substr(0, index);
		tmp = tmp.substr(index + 1);
		index = tmp.find(' ', 0);
		id = tmp.substr(0, index);
		nic = tmp.substr(index + 1);

		if (oper == "Enter") {
			for (int k = 0; k < uid.size(); k++)
				if (uid[k] == id)
					answer.push_back(nick[k] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		}
		if (oper == "Leave") {
			for (int k = 0; k < uid.size(); k++)
				if (uid[k] == id)
					answer.push_back(nick[k] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
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