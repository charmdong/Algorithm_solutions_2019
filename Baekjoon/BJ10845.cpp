/// ť

#include <iostream>
#include <queue>
#include <string>
using namespace std;

void solution(queue<int>& q, string command, int value =0);

int main()
{
		queue<int> q;
		string command;
		int testCnt;

		cin >> testCnt;
		while (testCnt--) {
				int value=0;
				cin >> command;
				if (command == "push")
						cin >> value;
				solution(q, command, value);
		}
		return 0;
}

void solution(queue<int>& q, string command, int value) {
		if (command == "push")
				q.push(value);
		else if (command == "pop") {
				if (q.empty())
						cout << "-1\n";
				else {
						cout << q.front() << endl;
						q.pop();
				}
		}
		else if (command == "size")
				cout << q.size() << endl;
		else if (command == "empty")
				q.empty() ? cout << "1\n" : cout << "0\n";
		else if (command == "front")
				q.empty() ? cout << "-1\n" : cout << q.front() << endl;
		else 
				q.empty() ? cout << "-1\n" : cout << q.back() << endl;
}