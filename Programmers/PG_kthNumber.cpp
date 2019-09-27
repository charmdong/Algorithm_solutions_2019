/**
 * PG : K번쨰 수
 */ 

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(vector<int> command : commands) {
        int start = command[0] - 1;
        int end = command[1] - 1;
        int k = command[2];

        vector<int> tmp;

        for(int index = start; index <= end; index++) {
            tmp.push_back(array[index]);
        }

        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k - 1]);
    }

    return answer;
}