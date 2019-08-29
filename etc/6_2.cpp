#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool hasWord(int y, int x, const string& word);
bool inRange(int y, int x);

const int dx[8] = { -1, -1, -1, 0, 0, 1,1,1 };
const int dy[8] = { -1, 0 ,1, -1, 1, -1,0,1 };
string board[5] = { "NNNNS", "NEEEN", "NEYEN", "NEEEN", "NNNNN" };

int main()
{
		string word = "YES";
		cout << "Is " << word << " exits?" << endl;
		hasWord(2, 2, word) ? cout << word +"\n": cout << "No...\n";
		return 0;
}

bool hasWord(int y, int x, const string& word) {
		if (!inRange(y, x)) return false;
		
		if (board[y][x] != word[0]) return false;

		if (word.size() == 1) return true;

		for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++) {
				x = x + dx[i];
				y = y + dy[i];

				if (!hasWord(y, x, word.substr(1)))
						return true;
		}
}

bool inRange(int y, int x) {
		return (y < 0 || x < 0 || y >= 5 || x >=5) ? false : true;
}