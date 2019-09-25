#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solution(vector<pair<int, string>> numberList, string sortType);

int main()
{
    int dataNum;
    string sortType;
    vector<pair<int, string>> numberList; // first : 가로 크기 , second : 숫자

    cin >> dataNum >> sortType;
    numberList.assign(dataNum, {0, 0});
    for(int i=0; i<dataNum; i++) {
        cin >> numberList[i].first >> numberList[i].second;
    }

    solution(numberList, sortType);

    return 0;
}

void solution(vector<pair<int, string>> numberList, string sortType) {
    // TODO 
}