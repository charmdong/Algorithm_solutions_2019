#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<bool> visited;
vector<vector<pair<int, int>>> board;
vector<Trade> res;

class Trade {
    public:
    vector<string> trace;
    int deposit;
    int fuel;

    Trade(){deposit = 100;}
    Trade(int f) : fuel(f) {deposit = 100;}
    void print() {
        for(string str : trace) {
            cout << str << " ";
        }
        cout << deposit << " " << fuel << endl;
    }
};

bool cmp(Trade &b1, Trade& b2) {
    return b1.deposit < b2.deposit;
}

vector<Trade> solution();

int main()
{
    int n;
    int initFuel;
    int edge;

    cin >> n >> initFuel;
    cin >> edge;
    board.assign(n, vector<pair<int, int>>(n, {0, 0}));

    string src, des;
    int dist;
    // 경로 설정
    for(int index = 0; index < edge; index++) {
        cin >> src >> des >> dist;
        board[stoi(src) - 65].push_back({stoi(des) - 65, dist});
    }



    return 0;
}

vector<Trade> solution() {
    vector<Trade> answer;

    

    sort(answer.begin(), answer.end(), cmp);
    return answer;
}