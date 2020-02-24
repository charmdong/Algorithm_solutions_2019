#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solution();

int main()
{
    solution();
    return 0;
}

void solution() {
    int n;
    string cmd;
    int num;
    vector<int> q;
    vector<int> numList(101, 0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> cmd;
        if(cmd == "enqueue") {
            cin >> num;
            q.push_back(num);
            numList[num]++;
        }
        else {
            
        }
    }
}