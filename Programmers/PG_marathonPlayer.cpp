/**
 * PG : 완주하지 못한 선수
 */ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion);

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int len = participant.size();

    for(int index = 0; index < len - 1; index++) {
        if(participant[index] != completion[index]) {
            return participant[index];
        } 
    }

    return participant.back();
}