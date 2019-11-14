/**
 * PG : 위장
 */ 

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes);

int main()
{

    return 0;
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, int> combination;

    for(auto row : clothes) {
        string type = row[1];

        combination[type]++;
    }

    for(auto iter = combination.begin(); iter != combination.end(); iter++) {
        answer *= (iter->second + 1);
    }
    
    return answer - 1;
}