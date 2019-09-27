#include <iostream>
#include <string>
#include <vector>
using namespace std;

long solution(vector<string>);

int main()
{
    vector<string> numList(4, "");
    
    for(int i=0; i<4; i++) {
        cin >> numList[i];
    }

    cout << solution(numList) << endl;

    return 0;
}

long solution (vector<string> numList) {
    long num1 = stol(numList[0] + numList[1]);
    long num2 = stol(numList[2] + numList[3]);

    return num1 + num2;
}